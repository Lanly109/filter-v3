//stage two complete
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const long long Maxn=100000+10;
long long n,m;
vector <long long> a;
inline long long read()
{
	long long s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
void ins(long long x)
{
	if(!a.size()){a.push_back(x);return;}
	if(x>=a[0ll]){a.insert(a.begin(),x);return;}
	if(x<=a[a.size()-1ll]){a.push_back(x);return;}
	long long l=0ll,r=a.size()-1ll;
	while(l<r)
	{
		long long mid=(l+r)>>1ll;
		if(a[mid]<x)r=mid;
		else l=mid+1ll;
	}
	a.insert(a.begin()+l,x);
}
int main()
{
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	n=read(),m=read();
	for(long long i=1;i<=n;++i)
	{
		long long tmp=read();
		ins(tmp);
		tmp=max(1ll,i*m/100ll);
		printf("%lld ",a[tmp-1ll]);
	}
	putchar('\n');
	return 0;
}
