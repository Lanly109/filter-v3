#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,w,m,a[601];
int main()
{
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	scanf("%d%d",&n,&w);
	//nn=1,ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		a[m]++;
		int now=max(1,i*w/100);
		//pp(now);
		for(int j=600;j>=0;j--)
		{
			now-=a[j];
			if(now<=0)
			{
				printf("%d ",j);
				break;
			}
		}
	}
	return 0;
}
