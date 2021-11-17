#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int k;
bool che(int x)
{
	k=0;
	while(x%2==0)
	{
		x/=2;	
	}
	if(x!=1)
	{
		return false;
	}
	return true;
}
void rty(int x)
{
	if(x==1)
	{
		return ;
	}
	int y=1;
	while(y<x)
	{
		y*=2;
	}
	if((x-y)==0)
	{
		cout<<x;
		return;
	}
	cout<<y/2<<" ";
	y/=2;
	if((x-y)!=0)
	{
		
		rty(x-y);
	}
	return ;
}
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int n;
	cin>>n;
	if(n%2==1)
	{
		cout<<-1;
		return 0;
	}
	else rty(n);
}
