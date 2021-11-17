#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
struct T{
	int ls,rs,num,l,r,v;
}p[2000010];
char c[2000010];
int a[400010];
int ch[400010];
int f[400010];
int q[2000010],st,ed,x,len,ret,cnt,n,Q;
void dfs(int x)
{
	if(p[x].num > 0)
	{
		p[x].v = a[p[x].num ];
		return ;
	}
	if(p[x].ls )dfs(p[x].ls );
	if(p[x].rs )dfs(p[x].rs );
	if(p[x].num == -1)
	{
		p[x].v = p[p[x].ls ].v ^1;
	}
	else if(p[x].num == -2)
	{
		p[x].v = (p[p[x].ls ].v & p[p[x].rs ].v); 
	}
	else if(p[x].num == -3)
	{
		p[x].v = (p[p[x].ls ].v | p[p[x].rs ].v );
	}
}
void cg(int l,int r)
{
	for(int i = l;i <= r;i ++)ch[i] = 0;
}
void dfs2(int x)
{
	if(p[x].ls == 0 )
	{
		return ;
	}
	if(p[x].num == -1)
	{
		dfs2(p[x].ls);
		return ;
	}
	int rs_v = p[p[x].rs ].v ;
	if(p[x].num == -2 && rs_v == 0)cg(p[p[x].ls ].l ,p[p[x].ls ].r );
	else if(p[x].num == -3 && rs_v == 1)cg(p[p[x].ls ].l ,p[p[x].ls ].r ); 
	else dfs2(p[x].ls );
	int ls_v = p[p[x].ls ].v ;
	if(p[x].num == -2 && ls_v == 0)cg(p[p[x].rs ].l ,p[p[x].rs ].r );
	else if(p[x].num == -3 && ls_v == 1)cg(p[p[x].rs ].l ,p[p[x].rs ].r );
	else dfs2(p[x].rs );
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	st = 1;ed = 0;
	int u = 0;
	gets(c+1);
	x = 1;len = strlen(c+1);
	while(x <= len)
	{
		if(c[x] == 'x')
		{
			x ++;
			ret = 0;
			while(c[x] >= '0' &&c[x] <= '9')
			{
				ret = ret * 10 + c[x] - '0';
				x++;
			}
			u++;
			f[ret] = u;
			p[++cnt].num = ret;
			q[++ed] = cnt;
			p[cnt].l = u;
			p[cnt].r = u;
			
		}
		if(c[x] == '!')
		{
			cnt ++;
			p[cnt].ls = q[ed];
			p[cnt].rs = 0;
			p[cnt].l = p[q[ed]].l ;
			p[cnt].r = p[q[ed]].r ;
			p[cnt].num = -1;
			q[ed] = cnt;
		}
		if(c[x] == '&')
		{
			cnt++;
			p[cnt].ls = q[ed-1];
			p[cnt].rs = q[ed];
			p[cnt].l = p[q[ed-1]].l ;
			p[cnt].r = p[q[ed]].r ;
			p[cnt].num = -2;
			ed --;
			q[ed] = cnt;
		}
		if(c[x] == '|')
		{
			cnt++;
			p[cnt].ls = q[ed-1];
			p[cnt].rs = q[ed];
			p[cnt].l = p[q[ed-1]].l ;
			p[cnt].r = p[q[ed]].r ;
			p[cnt].num = -3;
			ed --;
			q[ed] = cnt;
		}
		x++;
	}
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++)scanf("%d",&a[i]);
	for(int i = 1;i <= n;i ++)ch[i] = 1;
	dfs(cnt);
	dfs2(cnt);
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d",&x);
		printf("%d\n",p[cnt].v ^ ch[f[x]]);
	}
	return 0;
}
