#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
char s[100],ss[10000005],x;
int l,n,a[10000001],q,k;
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	while(true)
	{
		cin>>s;
		if(s[0]=='\n') return 0;
		if(s[0]=='x')
		{
			l++;
			ss[l]='x';
			l++;
			ss[l]=s[1];
		}
		else
		if(s[0]=='&'||s[0]=='|')
		{
			l++;
			ss[l]=s[0];
		}
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a[i]);
	}
//	for(int i=1;i<=l;i++)
//	{
//		cout<<ss[l];	
//	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&k);
		a[k]=(a[k]+1)%2;
		printf("%d",rand()%2);
	}
}
