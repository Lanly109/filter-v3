#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int dx[3]={-1,1,0};
int dy[3]={0,0,1};
int nn,mm;
int a[1005][1005],b[1005][1005];
long long ans;
void dfs(int x,int y,long long s)
{
	if(x==nn&&y==mm)
	{
		if(ans<s)
			ans=s;
	}
	else
	{
		for(int i=0;i<3;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx>0&&yy>0&&xx<=nn&&yy<=mm&&b[xx][yy]==0)
			{
				b[xx][yy]=1;
				dfs(xx,yy,s+a[xx][yy]);
				b[xx][yy]=0;
			}
		}
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&nn,&mm);
	for(int i=1;i<=nn;i++)
	{
		for(int j=1;j<=mm;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	memset(b,0,sizeof(b));
	ans=-999999999999999999;
	b[1][1]=1;
	dfs(1,1,a[1][1]);
	printf("%d",ans);
	return 0;
}
