#include<bits/stdc++.h>

using namespace std ;

int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+(ch^'0');ch=getchar();}
	return x*f;
}

#define mm 1050
int num[mm][mm]  ;
bool vis[mm][mm] ;

int n , m , ans = -1 ;

int xx[5] = {0 , 1 , 0 , 0 } ;
int yy[5] = {0 , 0 , 1 , -1 } ;

inline int max(int a , int b){return a > b ? a : b ;}

void dfs(int x , int y , int cnt){
	if(x == n && y == m){
//		printf("ans = %d cnt = %d\n" , ans , cnt) ;
		ans = max(ans , cnt) ;
	}
//	vis[x][y] = true ;
	for(int i = 1 ; i <= 3 ; ++i){
		int tx = x + xx[i] , ty = y + yy[i] ;
		if(tx < 1 || tx > n || ty < 1 || ty > m) continue ; 
		if(vis[tx][ty]) continue ;
//		printf("x:%d y:%d cnt:%d \n" , x , y , cnt) ;
		vis[tx][ty] = true ;
		dfs(tx , ty , cnt + num[x][y]) ;
		vis[tx][ty] = false ;
	}
} 

int main(){
	freopen("number.in" , "r" , stdin) ;
	freopen("number.out" , "w" , stdout) ;
	n = read() , m = read() ;
	memset(vis , false , sizeof(vis)) ; 
	for(int i = 1 ; i <= n ; ++i){
		for(int j = 1 ; j <= m ; ++j){
			num[i][j] = read() ;
		}
	}
	vis[1][1] = true ;
	dfs(1 , 1 , num[1][1]) ;
	printf("%d" , ans) ;
	return 0 ;
}
