#include<bits/stdc++.h>
using namespace std ;
int read(){
	int ans = 0 , f = 1 ; char ch = getchar() ;
	while(!isdigit(ch)){if(ch == '-')  f = -1 ; ch = getchar() ; }
	while(isdigit(ch)){ans = ans * 10 + (ch ^ '0') ; ch = getchar() ; }
	return ans * f ;
}
#define ddd double
const int maxn = 1010010 ; 
stack<int> s ; 
int a[maxn] ; 
char in[maxn] ; 
int n , q , len , cnt1 , cnt2 ; 
int solve(){
	int temp = 0 ; 
	while(s.size() ) s.pop() ; 
	for(int i = 1 ; i <= len ; i++){
		if(!isdigit(in[i]) && temp != 0){
			s.push(a[temp]) ; 
			temp = 0 ;  
		}
		if(isdigit(in[i])){
			temp = temp * 10 + in[i] - '0' ; 
		}
		else if(in[i] == '&'){
			int t1 = s.top() ; s.pop() ; 
			int t2 = s.top() ; s.pop() ; 
			s.push(t1 & t2) ; 
		}
		else if(in[i] == '|'){
			int t1 = s.top() ; s.pop() ; 
			int t2 = s.top() ; s.pop() ; 
			s.push(t1 | t2) ; 
		}
		else if(in[i] == '!'){
			int t1 = s.top() ; s.pop() ; 
			s.push(t1 ^ 1) ;
		}
	}
	return s.top() ; 
}
char ii[10] ; 
void substack1(){
	q = read() ; 
	while(q--){
		int pos = read() ; 
		a[pos] ^= 1 ; 
		printf("%d\n" , solve()) ; 
		a[pos] ^= 1 ;
	}
}
void substack2(){
	int tot1 = 0 ; 
	for(int i = 1 ; i <= n ; i++)
		if(a[i] == 1) tot1++ ; 
	q = read() ; 
	while(q--){
		int pos = read() ; 
		if(tot1 == n - 1 && a[pos] == 0)
		printf("1\n") ; 
		else printf("0\n") ;
	}
	return ; 
}
void substack3(){
	int tot1 = 0 ; 
	for(int i = 1 ; i <= n ; i++)
		if(a[i] == 1) tot1++ ; 
	q = read() ; 
	while(q--){
		int pos = read() ; 
		if(tot1 == 1 && a[pos] == 1)
		printf("0\n") ;
		else printf("1\n") ; 
	}
	return ; 
}
int main(){
	freopen("expr.in" , "r" , stdin) ; 
	freopen("expr.out" , "w" , stdout) ; 
	while(1){
		scanf("%s" , ii + 1) ; 
		int templen = strlen(ii + 1) ; 
		if(isdigit(ii[1])){
			int temp = 0 ; 
			for(int i = 1 ; i <= templen ; i++)
				temp = temp * 10 + ii[i] - '0' ; 
			n = temp ; 
			break ; 
		}
		for(int i = 1 ; i <= templen ; i++)
			in[++cnt1] = ii[i] ; 
	}
	len = strlen(in + 1) ; 
	for(int i = 1 ; i <= n ; i++)
		a[i] = read() ; 
	bool flag1 = 0 , flag2 = 0 , flag3 = 0 ; 
	for(int i = 1 ; i <= len ; i++){
		if(in[i] == '&') flag1 = 1 ; 
		if(in[i] == '|') flag2 = 1 ; 
		if(in[i] == '!') flag3 = 1 ; 
 	}
 	if(flag1 == 1 && flag2 == 0 && flag3 == 0)
 		substack2() ; 
 	else if(flag1 == 0 && flag2 == 1 && flag3 == 0)
 		substack3() ; 
 	else substack1() ; 
	return 0 ; 
}

