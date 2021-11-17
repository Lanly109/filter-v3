#include<cstdio>
#include<iostream>
using namespace std;
int n,x,cnt;
int a[1100];
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	scanf("%d",&n);
	if(n % 2 == 1)
	{
		printf("-1");
		return 0;
	}
	cnt = 1;x = 2;
	while(x <= n)
	{
		a[cnt] = x;
		cnt ++;
		x <<= 1;
	}
	cnt --;
	while(n > 0&&cnt >= 1)
	{
		if(a[cnt] <= n)
		{
			printf("%d ",a[cnt]);
			n -= a[cnt];
		}
		cnt --;
	}
	return 0;
}
