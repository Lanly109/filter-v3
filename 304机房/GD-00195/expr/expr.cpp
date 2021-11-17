#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
char ch[1000006];
int n,q,x,m,l,r,e;
int a[100005],b[100005];
int emmm()
{
	e=0;
	l=0;
	r=0;
	for(int i=1;i<=m;i++)
	{
		if(ch[i]=='x') 
		{
			if(l==0)
			{
				e=ch[i+1]-'0';
				l=a[e];
			}
			else if(r==0)
			{
				e=ch[i+1]-'0';
				r=a[e];
			}
		}
		if(ch[i]=='&')
		{
			l=l&r;
			r=0;
		}
		if(ch[i]=='|')
		{
			l=l|r;
			r=0;
		}
	}
	return l;
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	gets(ch+1);
	m=strlen(ch+1);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&x);
		if(b[x]>0)
		{
			printf("%d\n",b[x]);
			continue;
		}
		int y=a[x];
		a[x]=!a[x];
		b[x]=emmm();
		printf("%d\n",b[x]);
		a[x]=y;
	}
	return 0;
}


