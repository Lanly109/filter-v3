#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dx[3]={-1,0,1};
int dy[3]={0,1,0};
int mp[1001][1001];
bool vis[1001][1001];
int n,m,ans=-1e9,sum;
void dfs(int x,int y)
{
	sum+=mp[x][y];
	if(x==n&&y==m)
	{
		ans=max(sum,ans);
		return;
	}
	for(int i=0;i<3;i++)
	{
		if(!vis[x+dx[i]][y+dy[i]]&&mp[x+dx[i]][y+dy[i]]!=-0x7f)
		{
			vis[x+dx[i]][y+dy[i]]=true;
			dfs(x+dx[i],y+dy[i]);
			vis[x+dx[i]][y+dy[i]]=false;
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	memset(mp,-0x7f,sizeof(mp));
	memset(vis,0,sizeof(vis));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) scanf("%d",&mp[i][j]);
	}
	dfs(1,1);
	cout<<ans;
	return 0;
}
