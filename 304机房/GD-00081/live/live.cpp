#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,w,k,m;
int a[100001],b[100001];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	cin>>n>>w;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		m=i*w/100;
		k=max(1,m);
		for(int j=1;j<=i;j++) b[j]=a[j];
		sort(b+1,b+i+1,cmp);
		printf("%d ",b[k]);
	}
	return 0;
}
