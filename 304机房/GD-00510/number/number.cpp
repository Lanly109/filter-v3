//O(n^3)
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1007;
template<typename T> T read(T &t){
	t=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') t=t*10+(ch-'0'), ch=getchar();
	t *= f; return t;
}
int n, m, a[maxn][maxn], sum[maxn][maxn];
ll dp[maxn][maxn], up[maxn][maxn], dn[maxn][maxn];
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(n); read(m);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j){
			read(a[i][j]);
		}
	}
	for(int j = 1; j <= m; ++j){
		for(int i = 1; i <= n; ++i){
			ll sum = 0;
			//special judge
			if(i == 1 && j == 1) {
				dp[i][j] = a[i][j];
				continue;
			}else if(j == 1){
				dp[i][j] = dp[i-1][j]+a[i][j]; 
				continue;
			}
			dp[i][j] = dp[i][j-1]+a[i][j];
			//from up go down;
			sum = a[i][j];
			for(int k = i-1; k >= 1; --k){
				sum = sum + a[k][j];
				dp[i][j] = max(dp[i][j], dp[k][j-1]+sum);
			}
			//from down go up
			if(j != m){
				sum = a[i][j];
				for(int k = i+1; k <= n; ++k){
					sum = sum + a[k][j];
					dp[i][j] = max(dp[i][j], dp[k][j-1]+sum);
				}
			}
		}
	}
	cout << dp[n][m] << '\n';
	return 0;
}

