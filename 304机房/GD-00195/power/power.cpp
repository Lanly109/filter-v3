#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int n,r=1,t,flag;
long long f[30];
void dfs(int x)
{
	for(int i=1;i<=25;i++)
	{
		if(x==f[i])
		{
			printf("%d",f[i]);
			flag=1;
			return ;
		}
		if(x>f[i]&&x<f[i+1])
		{
			printf("%d ",f[i]);
			dfs(x-f[i]);
			if(flag==1) return ;
		}
	}
}
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	scanf("%d",&n);
	if(n%2==1) 
	{
		printf("-1");
		return 0;
	}
	for(int i=1;i<=25;i++)
	{
		f[++t]=r*2;
		r*=2;
		if(n==r)
		{
			printf("-1");
			return 0;
		}
	}
	for(int i=1;i<=25;i++)
	{
		if(n>f[i]&&n<f[i+1])
		{
			printf("%d ",f[i]);
			dfs(n-f[i]);
		}
	}
	return 0;
}
