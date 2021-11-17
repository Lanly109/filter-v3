#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	long long n;
	cin>>n;
	int i=0;
	bool a[10010]={0}; 
	if(n%2==1)
	{
		cout<<"-1";
	}
	else
	{
		while(n)
		{
			a[i++]=n%2;
			n/=2;
		}
		for(int j=i;j>=0;j--)
		{
			long long ans=1;
			if(a[j]!=0)
			{
				for(int q=1;q<=j;q++)
				{
					ans*=2;
				}
				cout<<ans<<" ";
			}
		}
	}
	return 0;
}
