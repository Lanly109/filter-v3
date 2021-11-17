#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
using namespace std;
int a[1002][1002];
bool f[1002][1002]={false};
int dx[3]={0,1,-1};
int dy[3]={1,0,0};
int n,m;
bool che(int u,int v)
{
	if(u>n||u<1||v>m||v<1||f[u][v]==true)
	{
		return false;
	}
	return true;
}

long long ans=0;
long long maxn=-100003;
void dfs(int x,int y)
{
	f[x][y]=true;
	ans+=a[x][y];
	if(x==n&&y==m)
	{
		return;
	}
	maxn=-100003;
	int k,l;
	for(int i=0;i<3;i++)
	{
		int xx=dx[i]+x;
		int yy=dy[i]+y;
		if(che(xx,yy))
		{
			if(maxn<a[xx][yy])
			{
				k=xx;
				l=yy;
				maxn=a[xx][yy];
			}
		}
	}
	dfs(k,l);
 } 
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	dfs(1,1);
	cout<<ans;
}
