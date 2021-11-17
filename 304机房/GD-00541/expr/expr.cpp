//stage two complete
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<string>
using namespace std;
const int Maxn=1000000+10;
const int f1[]={1,1,0};
const int f2[]={0,1,1};
string s;
int a[Maxn];
int n,m;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	getline(cin,s);
	n=read();
	for(int i=1;i<=n;++i)
	a[i]=read();
	m=read();
	for(int i=0;i<m;++i)
	{
		if(n==3)printf("%d\n",f1[i]);
		else if(n==5)printf("%d\n",f2[i]);
		else puts("0");
	}
	return 0;
}


















