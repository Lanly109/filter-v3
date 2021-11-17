#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int a[100002];
int b[100002];
int n;
int w;
int y; 
void noip(int x)
{
	int c=max(1,x*w/100);
	b[x]=a[x];
	sort(b+1,b+x+1);
	cout<<b[x-c+1]<<" ";
}
int main()
{
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		noip(i);
	}
}
