#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int a[24],n;
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	scanf("%d",&n);
	if(n%2==1)
	{
		printf("-1");
		return 0; 
	}
	a[0]=1;
	for(int i=1;i<=23;i++)
	{
		a[i]=a[i-1]*2;
		//printf("%d ",a[i]);
	}
	for(int i=23;i>=1;i--)
	{
		if(n>=a[i])
		{
			printf("%d ",a[i]);
			n-=a[i];
		}
	}
	return 0;
}//8388608,23
