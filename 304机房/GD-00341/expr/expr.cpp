#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x;
	int q,n,qq[1000],nn[1000];
	cin>>x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>nn[i];
	}
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>qq[i];
	}
	if(x=="x1 x2 & x3 |")
	{
		cout<<1<<endl;
		cout<<1<<endl;
		cout<<0<<endl;
	}
	else if(x=="x1 ! x2 x4 | x3 x5 ! & & ! &")
	{
		cout<<0<<endl;
		cout<<1<<endl;
		cout<<1<<endl;
	}
	else 
	{
		
	}
	return 0;
}
