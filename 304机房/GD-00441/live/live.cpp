#include <iostream>
#include <cstdio>
#define lowbit(x) (x & -x)
using namespace std;
const int maxv = 650;
int n,m,w,x,s[maxv];
int read(){
	int x = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + (c ^ 48),c = getchar();
	return x;
}
void add(int x,int k){
	while(x <= 601) s[x] += k,x += lowbit(x);
}
int query(int k){
	int x = 0;
	for(int i = 9; i >= 0; i --) if(x + (1 << i) <= 601 && s[x + (1 << i)] < k) x += 1 << i,k -= s[x];
	return x + 1;
}
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	n = read(),w = read();
	for(int i = 1; i <= n; i ++){
		x = read();
		add(601 - x,1);
		printf("%d ",601 - query(max(1,i * w / 100)));
	}
	return 0;
}
