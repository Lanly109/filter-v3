#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,k;
int a[31];
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n;
	if(n%2==1)
	{
		cout<<"-1";
		return 0;
	}
	a[0]=1;
	for(int i=1;i<=30;i++) a[i]=a[i-1]*2;
	k=upper_bound(a+1,a+32,n)-a-1;
	for(int i=k;i>=1;i--)
	{
		if(n==0) break;
		if((n/a[i])%2==1)
		{
			printf("%d ",a[i]);
			n-=a[i];
		}
	}
	return 0;
} 
