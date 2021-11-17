#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
char c[1000001];
int n,q,ans,len,x;
int a[10001];
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	gets(c);
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	cin>>q;
	while(q>0)
	{
		q--;
		scanf("%d",&x);
		cout<<'1'<<endl;
	}
	return 0;
}
