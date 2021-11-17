#include <bits/stdc++.h>

using namespace std;

int n,m;
int mp[1005][1005];
int maxt = -0x7fffffff;
bool vis[1005][1005];

int dx[4] = {-1,0,1};
int dy[4] = {0,1,0};
int dp[1005][1005];

void dfs(int nx,int ny,int nt){
	if(nx == n && ny == m){
		maxt = max(maxt,nt);
	}
	int fx,fy;
	for(int i = 0;i < 3;i++){
		fx = dx[i] + nx;
		fy = dy[i] + ny;
		if(fx <= 0 || fy <= 0 || fx > n || fy > m || vis[fx][fy])continue;
		vis[fx][fy] = 1;
		dfs(fx,fy,nt + mp[fx][fy]);
		vis[fx][fy] = 0;
	}
} 

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			scanf("%d",&mp[i][j]);
		}
	}
	
	
	if(n <= 5 && m <= 5){
		vis[1][1] = 1;
		dfs(1,1,mp[1][1]);
		printf("%d",maxt);
		return 0;
	}
	
	//不会写啊，只能这样了QAQ
	int z;
	int maxd;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			z = 0;
			maxd = -0x7fffffff;
			for(int k = j + 1;k <= m;k++){
				z += mp[i][k];
				maxd = max(maxd,mp[i - 1][k] + z);
			}
			dp[i][j] = max(dp[i - 1][j],max(dp[i][j - 1],maxd)) + mp[i][j];
		}
	}
	printf("%d",dp[n][m]);
	
	return 0;
} 
