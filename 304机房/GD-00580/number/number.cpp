#include<bits/stdc++.h>
using namespace std;

const int maxn = 10021;
int N, M;
int m[maxn][maxn], mx[maxn][maxn];
bool vis[maxn][maxn];
int ix[3] = {1, 0, -1}, iy[3] = {0, 1, 0};

void dfs(int x, int y, int sum){
	if(x < 0 || x >= N || y < 0 || y >= M)return;
	if(vis[x][y])return;
	if(sum < mx[x][y])return;
	mx[x][y] = sum;
	for(int i = 0; i < 3; i++){
		int xx = x + ix[i], yy = y + iy[i];
		vis[x][y] = true;
		dfs(xx, yy, sum + m[xx][yy]);
		vis[x][y] = false;
	}
}

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++)
		for(int j = 0; j < M; j++)
			scanf("%d", &m[i][j]);
	for(int i = 0; i < maxn; i++)
		for(int j = 0; j < maxn; j++)
			mx[i][j] = -10021;
	dfs(0, 0, m[0][0]);
	printf("%d\n", mx[N - 1][M - 1]);
	return 0;
}
