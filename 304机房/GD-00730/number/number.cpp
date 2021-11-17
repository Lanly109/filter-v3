#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,a[1010][1010];
long long ans=-10000000005,been[1010][1010];
bool flag[1010][1010];
inline int getnumber(){
	int z=1,x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')
			z=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar(); 
	}
	return z*x;
}
inline void dfs(int x,int y,long long now){
	if(x==n&&y==m){
		if(ans<now)
			ans=now;
		return; 
	} 
	been[x][y]=now;
	flag[x][y]=true;
	if(x+1<=n&&flag[x+1][y]==false&&now+a[x+1][y]>been[x+1][y])
		dfs(x+1,y,now+a[x+1][y]);
	if(x-1>=1&&flag[x-1][y]==false&&now+a[x-1][y]>been[x-1][y])
		dfs(x-1,y,now+a[x-1][y]);
	if(y+1<=m&&flag[x][y+1]==false&&now+a[x][y+1]>been[x][y+1])
		dfs(x,y+1,now+a[x][y+1]); 
	flag[x][y]=false;
	return;
}
int main(){
	memset(flag,false,sizeof(flag));
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	n=getnumber(),m=getnumber();
	for(register int i=1;i<=n;i++)
		for(register int j=1;j<=m;j++){
			a[i][j]=getnumber();
			been[i][j]=-10000000005;
		}
	dfs(1,1,a[1][1]);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
