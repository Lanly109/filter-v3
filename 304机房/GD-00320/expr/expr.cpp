#include<bits/stdc++.h>

using namespace std ;

#define mm 100050
char sym[1000050] ; int num[1000050] ;
int hs = 0 , hn = 0 ;

int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+(ch^'0');ch=getchar();}
	return x*f;
}

char s[mm] ;
int len = 0 ;

int a[mm] ;

void solve(int len){
	for(int i = 1 ; i <= len ; ++i){
		if(s[i] == 'x'){
			int where = (int)(s[i + 1] - '0') ;
//			printf("where = %d\n" , where) ;
			int now = (a[where]) ;
//			printf("now = %d\n" , now) ;
			num[++hn] = now ;
		}
		if(s[i] == '|' || s[i] == '&') sym[++hs] = s[i] ;
		if(s[i] == '!'){
//			printf("i = %d\n" , i) ;
			int num1 = num[hn] ; 
//			printf("num1 = %d\n" , num1) ;
			hn-- ;
			num1 = (num1 == 0 ? 1 : 0) ;
//			printf("num1 = %d\n" , num1) ;
			num[++hn] = num1 ;
//			for(int i = 1 ; i <= hn ; ++i){
//				printf("%d " , num[i]) ;
//			}
//			putchar('\n') ;
		}
		if(hn >= 2 && hs >= 1){
			int num1 = num[hn] ;
			hn-- ;
			int num2 = num[hn] ;
			hn-- ;
			int op = sym[hs] ;
			hs-- ;
			int fin = 0 ;
//			printf("num1 = %d num2 = %d\n" , num1 , num2) ;
			if(hs == '|'){
				fin = num1 | num2 ;
				num[++hn] = fin ;
//				for(int i = 1 ; i <= hn ; ++i){
//					printf("%d " , num[i]) ;
//				}
//				putchar('\n') ;
			} 
			if(hs == '&'){
				fin = num1 & num2 ;
				num[++hn] = fin ;
//				for(int i = 1 ; i <= hn ; ++i){
//					printf("%d " , num[i]) ;
//				}
//				putchar('\n') ;
			}
		}
	}
	printf("%d\n" , num[1]) ;
}

int main(){
	freopen("expr.in" , "r" , stdin) ;
	freopen("expr.out" , "w" , stdout) ;
	while(1){
		char ch = getchar() ;
		if(ch == '\n') break ;
		if(ch == ' ') continue ;
		s[++len] = ch ;
	}
	bool flag1 = true , flag2 = true ;
	for(int i = 1 ; i <= len ; ++i){
		if(s[i] == '0' || s[i] == '1') continue ;
		if(s[i] == '|') flag1 = false ;
		if(s[i] == '&') flag2 = false ;
	}
//	printf("len = %d\n" , len) ;
	int n = read() ;
	for(int i = 1 ; i <= n ; ++i) a[i] = read() ;
	int q = read() ;
//	printf("flag1 = %d\n" , flag1 ? 1 : 0) ;
//	printf("flag2 = %d\n" , flag2 ? 1 : 0) ;
	if(flag1){
		while(q--){
			int x = read() ;
			bool can = true ;
			a[x] = (a[x] == 0 ? 1 : 0) ;
			for(int i = 1 ; i <= n ; ++i) if(a[i] == 0) can = false ;
			can ? puts("1") : puts("0") ;
			a[x] = (a[x] == 0 ? 1 : 0) ;
		}
		return 0 ;
	}
	if(flag2){
		while(q--){
			int x = read() ;
			bool can = false ;
			a[x] = (a[x] == 0 ? 1 : 0) ;
			for(int i = 1 ; i <= n ; ++i) if(a[i] == 1) can = true ; 
			can ? puts("1") : puts("0") ;
			a[x] = (a[x] == 0 ? 1 : 0) ;
		}
		return 0 ;
	}
	while(q--){
		int x = read() ;
		a[x] = (a[x] == 0 ? 1 : 0) ;
//		for(int i = 1 ; i <= n ; ++i){
//			printf("a[%d] = %d\n" , i , a[i]) ;
//		}
		solve(len) ;
		a[x] = (a[x] == 0 ? 1 : 0) ;
	} 
	return 0 ;
}
