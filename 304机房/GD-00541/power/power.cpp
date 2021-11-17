//stage three complete
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
long long n;
inline long long read()
{
	long long s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	n=read();
	if(n & 1ll){puts("-1");return 0;}
	for(long long i=(long long)30;i>=(long long)0;--i)
	if(n & (1ll<<i))printf("%lld ",(1ll<<i));
	putchar('\n');
	return 0;
}
