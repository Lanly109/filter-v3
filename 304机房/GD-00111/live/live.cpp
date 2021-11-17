#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,w,x;
int num[610],cnt,sum[610];
inline int qread()
{
	int f = 0;char c = getchar();
	while(c < '0' || c > '9')c = getchar();
	while(c >= '0' && c <= '9')
	{
		f = (f << 3) + (f << 1) + c - '0';
		c = getchar();
	}
	return f;
}
int main()
{
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	n = qread();w = qread();
	for(int i = 1;i <= n;i ++)
	{
		x = qread();
		cnt = max(1,i*w/100);
		for(int i = x;i >= 0;i --)sum[i] --;
 		int j = upper_bound(sum+1,sum+601,-cnt)-sum;
		printf("%d ",j-1);
	}
	return 0;
}
