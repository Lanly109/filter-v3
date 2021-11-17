#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std; 
int n,m,a[1010][1010],ma = -100000000;
bool v[1010][1010];
void dfs(int x,int y,int f){
	if(x==n&&y==m){
		ma = max(ma,f);
		return ;
	}
	if(v[x+1][y]){
		v[x+1][y] = false;
		dfs(x+1,y,f+a[x+1][y]);
		v[x+1][y] = true;
	}
	if(v[x][y+1]){
		v[x][y+1] = false;
		dfs(x,y+1,f+a[x][y+1]);
		v[x][y+1] = true;
	}
	if(v[x-1][y]){
		v[x-1][y] = false;
		dfs(x-1,y,f+a[x-1][y]);
		v[x-1][y] = true;
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			cin >> a[i][j];
			v[i][j] = true;
		}
	}
	dfs(1,1,a[1][1]);
	cout << ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
