#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=1,fuck;
int matrix[1007][1007],ans[1007][1007],vis[1007][1007];
inline void dfs(int x,int y,int now){
	if(now>ans[x][y]){
		ans[x][y]=now;
//		cout<<x<<" "<<y<<" "<<now<<endl;
	}
			
	if(x==n&&y==m)
		return ;

	if(vis[x+1][y]==0){
		vis[x+1][y]=1;
		dfs(x+1,y,now+matrix[x+1][y]);
		vis[x+1][y]=0;
	}

	if(vis[x][y+1]==0){
		vis[x][y+1]=1;
		dfs(x,y+1,now+matrix[x][y+1]);
		vis[x][y+1]=0;
	}

	if(vis[x-1][y]==0){
		vis[x-1][y]=1;
		dfs(x-1,y,now+matrix[x-1][y]);
		vis[x-1][y]=0;
	}
	return ;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n*m<=25){
		for(int i=0;i<=n+1;i+=n+1){
			for(int j=0;j<=m+1;++j){
				vis[i][j]=1;
			}
		}
		for(int i=0;i<=n+1;++i){
			for(int j=0;j<=m+1;j+=m+1){
				vis[i][j]=1;
			}
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				scanf("%d",&matrix[i][j]);
				ans[i][j]=-100000000;
			}
		}
		dfs(1,1,matrix[1][1]);
		printf("%d",ans[n][m]);
	}//20pts
 	else{
 		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				scanf("%d",&matrix[i][j]);
				fuck+=matrix[i][j];
			}
		}
		printf("%d",fuck);
 	
	 }
	return 0;
} 
