#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[1005][1005],f[1005][1005],g[1005][1005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%lld",a[i]+j);
	f[1][1]=g[1][1]=a[1][1];
	for(int i=2;i<=n;i++)f[i][1]=g[i][1]=f[i-1][1]+a[i][1];
	for(int j=2;j<m;j++){
		f[1][j]=max(f[1][j-1],g[1][j-1])+a[1][j];
		for(int i=2;i<=n;i++)f[i][j]=max(max(f[i][j-1],g[i][j-1]),f[i-1][j])+a[i][j];
		g[n][j]=max(f[n][j-1],g[n][j-1])+a[n][j];
		for(int i=n-1;i;i--)g[i][j]=max(max(f[i][j-1],g[i][j-1]),g[i+1][j])+a[i][j];
	}
	f[1][m]=max(f[1][m-1],g[1][m-1])+a[1][m];
	for(int i=2;i<=n;i++)f[i][m]=max(max(f[i][m-1],g[i][m-1]),f[i-1][m])+a[i][m];
	printf("%lld\n",f[n][m]);
	return 0;
}
