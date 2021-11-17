#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f3f3f3f
int n,m,a[1005][1005];
long long dp[3][1005][1006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=2;i<=n;i++) for(int k=0;k<3;k++) dp[k][i][0]=-inf;
	for(int j=1;j<=m;j++) for(int k=0;k<3;k++) dp[k][0][j]=dp[k][n+1][j]=-inf;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++) dp[0][i][j]=max(dp[0][i][j-1],max(dp[1][i][j-1],dp[2][i][j-1]))+a[i][j];
		for(int i=1;i<=n;i++) dp[1][i][j]=max(dp[0][i-1][j],dp[1][i-1][j])+a[i][j];
		for(int i=n;i>=1;i--) dp[2][i][j]=max(dp[0][i+1][j],dp[2][i+1][j])+a[i][j];
	}
	cout<<max(dp[0][n][m],dp[1][n][m]);
	return 0;
}
