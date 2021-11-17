#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int n,m,ans=-999999999,t;
int a[1005][1005];
int dx[3]={0,1,-1};
int dy[3]={1,0,0};
bool f[1005][1005];
bool check(int x,int y)
{
	if(x<1||y<1||x>n||y>m) return false;
	if(f[x][y]==true) return false;
	return true;
}
void dfs(int x,int y,int p)
{
	if(x==n&&y==m)
	{
		ans=max(ans,p);
		return ;
	}
	for(int i=0;i<3;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(check(nx,ny))
		{
			cout<<nx<<" "<<ny<<" "<<p+a[nx][ny]<<endl; 
			f[nx][ny]=true;
			dfs(nx,ny,p);
			f[nx][ny]=false;
		}
	}
}
int main()
{
//	freopen("number.in","r",stdin);
//	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	dfs(1,1,a[1][1]);
	printf("%d",ans);
	return 0;
}
