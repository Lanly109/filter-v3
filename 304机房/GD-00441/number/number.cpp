#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1050;
const long long inf = 1e18;
int n,m,a[maxn][maxn];
long long f[maxn][maxn];
int read(){
	int x = 0,f = 1;
	char c = getchar();
	while(c < '0' || c > '9'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9') x = x * 10 + (c ^ 48),c = getchar();
	return x * f;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	n = read(),m = read();
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			a[i][j] = read();
	for(int i = 1; i <= n; i ++) f[1][i] = f[1][i - 1] + a[i][1];
	for(int i = 2; i <= m; i ++){
		int s = 0;
		long long mx = -inf;
		for(int j = 1; j <= n; j ++){
			mx = max(mx,f[i - 1][j] - s);
			s += a[j][i];
			f[i][j] = mx + s;
		}
		s = 0,mx = -inf;
		for(int j = n; j >= 1; j --){
			mx = max(mx,f[i - 1][j] - s);
			s += a[j][i];
			f[i][j] = max(f[i][j],mx + s);
		}
	}
//	for(int i = 1; i <= m; i ++){
//		for(int j = 1; j <= n; j ++) cout << f[i][j] << ' ';
//		cout << endl;
//	}
	printf("%lld\n",f[m][n]);
	return 0;
}
