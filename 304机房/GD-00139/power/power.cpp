//Ta&Shan?Zhi@Shi%
#include<bits/stdc++.h>
using namespace std ; 
int read(){
	int ans = 0 , f = 1 ; char ch = getchar() ; 
	while(!isdigit(ch)){if(ch == '-') f = -1 ; ch = getchar() ; }
	while(isdigit(ch)){ans = ans * 10 + (ch ^ '0') ; ch = getchar() ; }
	return ans * f ; 
}
#define ddd double 
int n ; 
stack<int> s ; 
int po[31] ; 
int main(){
	freopen("power.in" , "r" , stdin) ; 
	freopen("power.out" , "w" , stdout) ; 
	n = read() ; 
	if(n & 1){
		printf("-1") ; 
		return 0 ; 
	}
	po[0] = 1 ; 
	for(int i = 1 ; i <= 30 ; i++)
		po[i] = po[i - 1] * 2 ;
	for(int i = 2 ; i <= 30 ; i++){
		if(1 << (i - 1) & n)
			s.push(po[i - 1]) ; 
	}
	while(s.size() ){
		printf("%d " , s.top() ) ; 
		s.pop() ; 
	}
	return 0 ; 
} 
