#include<bits/stdc++.h>
using namespace std;
int a[1005][1005],n,m,z=0;
int dy[4]={0,0,1,0};
int dx[4]={0,-1,0,1};
bool ans[1005][1005],flag=false;
int f[1005][1005];
void dfs(int x,int y){
	if(x==n&&y==m){
		z=0;
		return ;
	}
	for(int i=1;i<=3;i++){
		int xx=dx[i]+x;
		int yy=dy[i]+y;
		ans[xx][yy]=true;
		if(xx!=0&&yy!=0&&xx!=n+1&&yy!=m+1) z+=a[xx][yy],dfs(xx,yy);
		ans[xx][yy]=false;
		//z-=a[xx][yy];
		f[xx][yy]=max(f[xx][yy],z);
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	dfs(1,1);
	printf("%d",f[n][m]);
}
