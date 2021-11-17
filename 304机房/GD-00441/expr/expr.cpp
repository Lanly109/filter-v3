#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 1e5 + 50,maxm = 1e6 + 50;
int n,m,q,rt,cnt,a[maxm],p[maxm],ls[maxm],rs[maxm],ans[maxn];
bool v[maxn],val[maxm];
char c;
int read(){
	int x = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + (c ^ 48),c = getchar();
	return x;
}
int gt(){
	c = getchar();
	if(c == 'x') return read();
	else if(c == '!') return -1;
	else if(c == '&') return -2;
	else return -3;
}
int build(int &u,int k){
	u = ++cnt,p[u] = a[k];
	if(a[k] > 0){
		val[u] = v[a[k]];
		return k;
	}else if(a[k] == -1){
		int t = build(ls[u],k - 1);
		val[u] = !val[ls[u]];
		return t;
	}else{
		int t = build(rs[u],k - 1);
		t = build(ls[u],t - 1);
		if(a[k] == -2) val[u] = val[ls[u]] & val[rs[u]];
		else val[u] = val[ls[u]] | val[rs[u]];
		return t;
	}
}
void dfs(int u){
	if(p[u] > 0){
		ans[p[u]] = 1;
		return;
	}
	if(p[u] == -1) dfs(ls[u]);
	else if(p[u] == -2){
		if(val[ls[u]] && !val[rs[u]]) dfs(rs[u]);
		else if(!val[ls[u]] && val[rs[u]]) dfs(ls[u]);
		else if(val[ls[u]] && val[rs[u]]) dfs(ls[u]),dfs(rs[u]);
	}else if(p[u] == -3){
		if(val[ls[u]] && !val[rs[u]]) dfs(ls[u]);
		else if(!val[ls[u]] && val[rs[u]]) dfs(rs[u]);
		else if(!val[ls[u]] && !val[rs[u]]) dfs(ls[u]),dfs(rs[u]);
	}
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	a[++m] = gt();
	while(a[m] > 0 || getchar() == ' ') a[++m] = gt();
//	for(int i = 1; i <= m; i ++) cout << a[i] << ' ';
	n = read();
	for(int i = 1; i <= n; i ++) v[i] = read();
	build(rt,m);
//	for(int i = 1; i <= cnt; i ++) cout << i << ' ' << p[i] << ' ' << ls[i] << ' ' << rs[i] << ' ' << val[i] << endl;
	dfs(rt);
	q = read();
	while(q --) printf("%d\n",val[rt] ^ ans[read()]);
	return 0;
}
