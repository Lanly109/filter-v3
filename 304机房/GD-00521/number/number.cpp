#include<bits/stdc++.h>
using namespace std;
int n,m,a[1021][1021],fl[1021][1021],fu[1021][1021],fd[1021][1021],f[1021][1021]; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			fl[i][j]=f[i][j]=fd[i][j]=fu[i][j]=-1141919810;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++)	
			fl[i][j]=f[i][j-1]+a[i][j];
		if(j!=1)
		for(int i=n-1;i>=1;i--){
			fd[i][j]=max(fd[i+1][j],fl[i+1][j])+a[i][j];
		}
		for(int i=2;i<=n;i++){
			fu[i][j]=max(fu[i-1][j],fl[i-1][j])+a[i][j];
		}
		for(int i=1;i<=n;i++)	
			f[i][j]=max(fl[i][j],max(fu[i][j],fd[i][j]));
	}
	cout<<f[n][m];
}
