#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int n;
double w;
int a[100005];
int main()
{
//	freopen("live.in","r",stdin);
//	freopen("live.out","w",stdout);
	cin>>n>>w;
	w=w/100.0; 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		int u=i*w;
		int h=max(1,u);
		if(i!=1)
		{
			 sort(a+1,a+i+1);
		}
		int fs=a[i+1-h];
		printf("%d ",fs);
	}
	return 0;
} 
