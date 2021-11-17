#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define ll long long
const ll inf = 1e15;

template <class T>
inline void read(T& a){
	T x = 0, s = 1;
	char c = getchar();
	while(!isdigit(c)){ if(c == '-') s = -1; c = getchar();  }
	while(isdigit(c)){ x = x * 10 + (c ^ '0'); c = getchar();  }
	a = x * s;
	return ;
}

int n, m;  
ll a[N][N];
namespace subtask1{

	int fx[4] = {0, 0, 1, -1};
	int fy[4] = {0, 1, 0, 0}; 

	inline bool judge(int x, int y){
		return (x >= 1 && x <= n && y >= 1 && y <= m); 
	}		

	ll ans = -inf; 
	bool vis[N][N]; 

	void dfs(int x, int y, ll w){
		if(x == n && y == m){
			ans = max(ans, w);
			return ; 
		}	
		for(int i = 1; i <= 3; i++){
			int r = x + fx[i];
			int c = y + fy[i];
			if(!vis[r][c] && judge(r, c)){
				vis[r][c] = 1; 
				dfs(r, c, w + a[r][c]); 
				vis[r][c] = 0; 
			}
		}
		return ; 
	}
	void main(){
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				read(a[i][j]); 
		vis[1][1]= 1;  
		dfs(1, 1, a[1][1]); 
		cout << ans << endl; 
		return ; 
	}
}

ll dp[N][N]; 

int main(){
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout); 
	read(n), read(m);
	if(n <= 5 && m <= 5){
		subtask1::main();
		return 0; 
	}
	memset(dp, -0x3f, sizeof(dp)); 
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			read(a[i][j]); 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i == 1 && j == 1)
				dp[i][j] = a[i][j]; 
			else dp[i][j] = max(dp[i][j], max(dp[i-1][j] + a[i][j], max(dp[i][j-1] + a[i][j], dp[i][j+1] + a[i][j]))); 
		}
	}
	cout << dp[n][m] << endl; 
	return 0;
}

