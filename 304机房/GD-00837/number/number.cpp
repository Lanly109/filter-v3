#include<bits/stdc++.h>
using namespace std;
int n,m;
int c[1005][1005];
int dis[1005][1005];
int vis[1005][1005];
int ans=-1000000000;
void dfs(int x,int y,int cnt){
	if(x==n&&y==m){
		ans=max(ans,cnt);
		return ;
	}
	if(dis[x][y]>cnt)return ;
	dis[x][y]=cnt;
	if(x==n){
		if(!vis[x-1][y]){
			vis[x-1][y]=1;
			dfs(x-1,y,cnt+c[x-1][y]);
			vis[x-1][y]=0; 
		}
		if(!vis[x][y+1]){
			vis[x][y+1]=1;
			dfs(x,y+1,cnt+c[x][y+1]);
			vis[x][y+1]=0; 
		}
	}
	else if(y==m){
		if(!vis[x+1][y]){
			vis[x+1][y]=1;
			dfs(x+1,y,cnt+c[x+1][y]);
			vis[x+1][y]=0; 
		}
	}
	else{
		if(!vis[x+1][y]){
			vis[x+1][y]=1;
			dfs(x+1,y,cnt+c[x+1][y]);
			vis[x+1][y]=0; 
		}
		if(!vis[x][y+1]){
			vis[x][y+1]=1;
			dfs(x,y+1,cnt+c[x][y+1]);
			vis[x][y+1]=0; 
		}
		if(!vis[x-1][y]&&x!=1){
			vis[x-1][y]=1;
			dfs(x-1,y,cnt+c[x-1][y]);
			vis[x-1][y]=0; 
		}
	}
	return ;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
			dis[i][j]=-1000000000;
		}
	}
	vis[1][1]=1;
	dfs(1,1,c[1][1]);
	cout<<ans;
	return 0;
} 
