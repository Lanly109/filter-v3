//stage two complete
//long long required, please double check
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const long long Maxn=1010;
const long long Maxm=4040;
const long long inf=(1ll<<60);
long long f[Maxn][Maxn],a[Maxn][Maxn];
long long s[Maxn][Maxn];
long long maxv[Maxm],add[Maxm];
long long n,m;
inline long long read()
{
	long long s=0,w=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0' && ch<='9')s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
inline void check(long long &x,long long y)
{
	x=max(x,y);
}
inline void push_up(long long k)
{
	maxv[k]=max(maxv[k<<1],maxv[k<<1|1]);
}
inline void upd(long long k,long long v)
{
	add[k]+=v;
	maxv[k]+=v;
}
inline void push_down(long long k)
{
	if(!add[k])return;
	upd(k<<1,add[k]);
	upd(k<<1|1,add[k]);
	add[k]=0ll;
}
void build(long long k,long long l,long long r,long long pos)
{
	add[k]=0ll;
	if(l==r)
	{
		maxv[k]=f[l][pos];
		return;
	}
	long long mid=(l+r)>>1;
	build(k<<1,l,mid,pos);
	build(k<<1|1,mid+1,r,pos);
	push_up(k);
}
void modify(long long k,long long l,long long r,long long x,long long y,long long v)
{
	if(x<=l && r<=y)return upd(k,v);
	push_down(k);
	long long mid=(l+r)>>1;
	if(x<=mid)modify(k<<1,l,mid,x,y,v);
	if(mid<y)modify(k<<1|1,mid+1,r,x,y,v);
	push_up(k);
}
long long query(long long k,long long l,long long r,long long x,long long y)
{
	if(x<=l && r<=y)return maxv[k];
	push_down(k);
	long long mid=(l+r)>>1,ret=-inf;
	if(x<=mid)ret=query(k<<1,l,mid,x,y);
	if(mid<y)check(ret,query(k<<1|1,mid+1,r,x,y));
	return ret;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	n=read(),m=read();
	for(long long i=1;i<=n;++i)
	for(long long j=1;j<=m;++j)
	{
		a[i][j]=read();
		f[i][j]=-inf;
	}
	for(long long j=1;j<=m;++j)
	for(long long i=1;i<=n;++i)
	s[i][j]=s[i-1][j]+a[i][j];
	for(long long i=1;i<=n;++i)
	f[i][1]=s[i][1];
	if(n<=300 && m<=300)
	{
		for(long long j=2;j<=m;++j)
		for(long long i=1;i<=n;++i)
		for(long long k=1;k<=n;++k)
		{
			long long x=i,y=k;
			if(x>y)swap(x,y);
			check(f[i][j],f[k][j-1]+s[y][j]-s[x-1][j]);
		}
		printf("%lld\n",f[n][m]);
		return 0;
	}
	for(long long j=2;j<=m;++j)
	{
		build(1,1,n,j-1);
		for(long long i=1;i<=n;++i)
		{
			modify(1,1,n,1,i,a[i][j]);
			check(f[i][j],query(1,1,n,1,i));
		}
		build(1,1,n,j-1);
		for(long long i=n;i;--i)
		{
			modify(1,1,n,i,n,a[i][j]);
			check(f[i][j],query(1,1,n,i,n));
		}
	}
	printf("%lld\n",f[n][m]);
	return 0;
}
