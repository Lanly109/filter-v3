#include<iostream>
#include<cstdio>
using namespace std;
int f[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n,m;
int v[7001][7001];
bool book[7001][7001];
int ans = -2102345678;
void DFS(int x,int y,int ta){
	if(x==n&&y==m){
		ans = max(ans,ta);
	}
	for(int i=0; i<=4; i++){
		int r=x+f[i][0],c=y+f[i][1];
		if(r>=1&&r<=n&&c>=1&&c<=m && book[r][c] == false){
			book[r][c] = true;
			DFS(r,c,ta+v[r][c]);
			book[r][c] = false;
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>v[i][j];
			book[i][j] = false;
		}
	}
	book[1][1] = true;
	DFS(1,1,v[1][1]);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

