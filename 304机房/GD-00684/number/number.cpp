#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
int n,m,a[1005][1005],d[4][2]={{1,0},{-1,0},{0,1},{0,-1}},vis[1005][1005];
long long f[1005][1005];
void dfs(int x,int y,long long sum)
{
	if(x<1||x>n||y<1||y>m) return;
	f[x][y]=max(sum,f[x][y]);
	if(x==n&&y==m) return;
	vis[x][y]=1;
	for(int i=0;i<4;i++){
		int nx=x+d[i][0],ny=y+d[i][1];
		if(!vis[nx][ny]&&nx>=1&&nx<=n&&ny>=1&&ny<=m){
			sum+=a[nx][ny];
			vis[nx][ny]=1;
			dfs(nx,ny,sum);
			sum-=a[nx][ny];
			vis[nx][ny]=0;
		}
	}
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			f[i][j]=-1e9;
		}
	}
	dfs(1,1,a[1][1]);
	cout<<f[n][m];
	fclose(stdin);fclose(stdout);
	
	return 0;
} 
