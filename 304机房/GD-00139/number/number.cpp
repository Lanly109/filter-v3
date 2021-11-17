#include<bits/stdc++.h>
using namespace std ;
int read(){
	int ans = 0 , f = 1 ; char ch = getchar() ;
	while(!isdigit(ch)){if(ch == '-')  f = -1 ; ch = getchar() ; }
	while(isdigit(ch)){ans = ans * 10 + (ch ^ '0') ; ch = getchar() ; }
	return ans * f ;
}
#define int long long 
const int maxn = 1010 ; 
int n , m , ans = -9999999999999; 
int matrix[maxn][maxn] , f[maxn][maxn][3] ; 
bool vis[maxn][maxn] ; 
int dx[3] = {-1 , 1 , 0} ; 
int dy[3] = {0 , 0 , 1 } ;  
void dfs(int x , int y , int have){
	if(x == n && y == m){
		ans = max(ans , have) ; 
		return ; 
	}
	for(int i = 0 ; i < 3 ; i++){
		int tx = x + dx[i] , ty = y + dy[i] ; 
		if(!vis[tx][ty] && tx <= n && tx >= 1 && ty <= m && ty >= 1){
			vis[tx][ty] = 1 ; 
			dfs(tx , ty , have + matrix[tx][ty]) ; 
			vis[tx][ty] = 0 ; 
		}
	}
	return; 
}
void substack1(){
	vis[1][1] = 1 ; 
	dfs(1 , 1 , matrix[1][1]) ;  
	printf("%lld" , ans) ; 
}
int rdfs(int x , int y , int k){
	if(x < 1 || x > n || y < 1 || y > m ) return -999999999999; 
	if(f[x][y][k] != -999999999999) return f[x][y][k] ; 
	if(x == n && y == m){
		return f[x][y][1] = f[x][y][2] = f[x][y][0] = matrix[x][y] ; 
	}
	f[x][y][k] = matrix[x][y] ; 
	int maxx = -999999999999 ;
	if(k == 0){
		maxx = max(rdfs(x - 1 , y , 2) , maxx ) ; 
		maxx = max(rdfs(x + 1 , y , 1) , maxx ) ; 
		maxx = max(rdfs(x , y + 1 , 0) , maxx ) ; 
		f[x][y][k] += maxx ; 
		return f[x][y][k] ; 
	}
	else if(k == 1){
		maxx = max(rdfs(x + 1 , y , 1) , maxx ) ; 
		maxx = max(rdfs(x , y + 1 , 0) , maxx ) ; 
		f[x][y][k] += maxx ; 
		return f[x][y][k] ; 
	}
	if(k == 2){
		maxx = max(rdfs(x - 1 , y , 2) , maxx ) ; 
		maxx = max(rdfs(x , y + 1 , 0) , maxx ) ; 
		f[x][y][k] += maxx ; 
		return f[x][y][k] ; 
	}
}
void substack2(){
	printf("%lld" , rdfs(1 , 1 , 1)) ; 
}
#undef int 
int main(){
	freopen("number.in" , "r" , stdin) ; 
	freopen("number.out" , "w" , stdout) ; 
#define int long long 
	n = read() , m = read() ; 
	for(int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			matrix[i][j] = read() ,f[i][j][1] = f[i][j][2] = f[i][j][0] = -999999999999 ; 
	if(n <= 10 && m <= 10 ) {
		substack1() ; 
		return 0 ; 
	}
	substack2() ; 
	return 0 ; 
}
