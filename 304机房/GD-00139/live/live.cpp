#include<bits/stdc++.h>
using namespace std ;
int read(){
	int ans = 0 , f = 1 ; char ch = getchar() ;
	while(!isdigit(ch)){if(ch == '-') f = -1 ; ch = getchar() ; }
	while(isdigit(ch)){ans = ans * 10 + (ch ^ '0') ; ch = getchar() ; }
	return ans * f ;
}
#define ddd double
int cnt[1000] ; 
int n , w ; 
void solve(int k){
	for(int i = 600 ; i >= 0 ; i--){
		if(k - cnt[i] <= 0){
			printf("%d " , i) ; 
			return ; 
		}
		k -= cnt[i] ; 
	}
}
int main(){
	freopen("live.in" , "r" , stdin) ; 
	freopen("live.out" , "w" , stdout) ; 
	n = read() , w = read() ; 
	for(int i = 1 ; i <= n ; i++){
		int now = read() ; 
		cnt[now]++ ; 
		solve(max(1 , i * w / 100)) ; 
	}
	return 0 ; 
}
