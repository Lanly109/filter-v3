#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	int n,w,a[100010]={0},paiming[100010]={1},ans[100010]={0};
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		int m=max(1,i*w/100);
		cin>>a[i];
		for(int j=1;j<=i;j++)
		{
			if(a[i]<a[j])
			{
				paiming[i]++;
			}
			else
			{
				paiming[j]++;
			}
		}
		for(int q=1;q<=i;q++)
		{
			if(paiming[q]==m)
			{
				ans[i]=a[q];
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}
