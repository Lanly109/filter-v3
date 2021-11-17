#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,a[100001],b[100001],k;
int main()
{
//	freopen("live.in","r",stdin);
//	freopen("live.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		sort(a+1,a+i+1);
		k=floor(i*m/100);
		k=max(k,1);
		b[i]=a[i-k+1]; 
	}
	for (int i=1;i<=n;i++)
	{
		cout<<b[i]<<" ";
	}
}
