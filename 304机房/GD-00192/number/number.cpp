#include<bits/stdc++.h>
using namespace std;
int vis[5111][5111],mp[5111][5111],n,m;
int maxans=-1e9;
void dfs(int x,int y,int ans){
	if(x>n||y>m||x<1||y<1)return;
	if(vis[x][y])return;
	vis[x][y]=1;
	ans+=mp[x][y];
	if(x==n&&y==m){
		vis[x][y]=false;
		maxans=max(ans,maxans);
		return;
	}
	dfs(x+1,y,ans);
	dfs(x-1,y,ans);
	dfs(x,y+1,ans);
	vis[x][y]=false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&mp[i][j]);
	dfs(1,1,0);
	printf("%d",maxans);
}
