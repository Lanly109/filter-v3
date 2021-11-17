#include<iostream>
#include<cstdio>
using namespace std;
int cube[1005][1005],n,m,ans[1005][1005];
bool vis[1005][1005]={1};
void dfs(int x,int y,int a,int b){
	if(vis[x][y]==0){
		if(x==n&&y==m){
			ans[x][y]=max(ans[n][m],ans[a][b]+cube[n][m]);
			vis[a][b]=0;
			return ;
		}
		ans[x][y]=ans[a][b]+cube[x][y];
		vis[x][y]=1;
		dfs(x,y+1,x,y);
		dfs(x+1,y,x,y);
		dfs(x-1,y,x,y);
	}
	
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	for(int k=1;k<=m;k++){
		cin>>cube[i][k];
		vis[i][k]=0;
	}
	ans[1][1]=cube[1][1];
	dfs(1,1,0,0);
	cout<<ans[n][m];
	return 0;
}
