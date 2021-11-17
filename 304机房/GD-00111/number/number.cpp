#include<cstdio>
#include<iostream>
using namespace std;
int n,m,a[1010][1010],sum,f[1010][1010],cnt;
const int inf = 999999999;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 1;j <= m;j ++)
			scanf("%d",&a[i][j]);
	}
	for(int i = 1;i <= n;i ++)f[i][1] = f[i-1][1] + a[i][1];
	for(int i = 1;i <= n;i ++)
	{
		for(int j = 2;j <= m;j ++)f[i][j] = -inf;
	}
	for(int j = 2;j <= m;j ++)
	{
		sum = -inf;
		for(int i = 1;i <= n;i ++)
		{
			if(f[i][j-1] > sum)
			{
				sum = f[i][j-1];
			}
			sum += a[i][j];
			f[i][j] = max(f[i][j],sum);
		}
		sum = -inf;
		for(int i = n;i >= 1;i --)
		{
			if(f[i][j-1] > sum)
			{
				sum = f[i][j-1];
			}
			sum += a[i][j];
			f[i][j] = max(f[i][j],sum);
		}
	}
	printf("%d",f[n][m]);
	return 0;
}
