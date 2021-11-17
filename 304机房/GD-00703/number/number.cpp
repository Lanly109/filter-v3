#include <iostream>
#include <fstream>

using namespace std;

int n, m;
int map[1010][1010];
bool edge[1010][1010]; //有x,y, edge[x][y]能否通向下一个 edge[x - 1][y]能否通向上一个 
long long ans = 0LL, res = -20000000000;
/*
class Graph {
public:
	void init(int num) {
		v = num;
		for(int i = 1; i <= v; i++) {
			for(int j = 1; j <= v; j++) {
				gmat[i][j] = false;
			}
		}
	}
	void addEdge(int p, int q) {
		gmat[p][q] = true;
	}
	void eraEdge(int p, int q) {
		gmat[p][q] = false;
	}
	bool ifEdge(int p, int q) {
		return gmat[p][q] | gmat[q][p];
	}
	bool gmat[10100][10100];
	int v;
};
Graph g;
*/
void dfs(int x, int y) {
	if(x == n && y == m) {
		res = max(res, ans);
		return ;
	}
	if(edge[x - 1][y]) {
		ans += map[x - 1][y];
		edge[x - 1][y] = false;
		dfs(x - 1, y);
		edge[x - 1][y] = true;
		ans -= map[x - 1][y];
	}
	if(edge[x][y]) {
		ans += map[x + 1][y];
		edge[x][y] = false;
		dfs(x + 1, y);
		edge[x][y] = true;
		ans -= map[x + 1][y];
	}
	if(y != m) {
		ans += map[x][y + 1];
		dfs(x, y + 1);
		ans -= map[x][y + 1];
	}
}
int main() {
	ifstream ifs("number.in");
	ofstream ofs("number.out");
	ifs >> n >> m; //n行数 m列数
	//g.init(n * m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			ifs >> map[i][j]; //formula:x * m + y
			if(i != n) {
				edge[i][j] = true;
			}
		}
	}
	ans = map[1][1];
	dfs(1, 1);
	ofs << res << endl;
	return 0;
}
