#include<bits/stdc++.h>

using namespace std ;

int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+(ch^'0');ch=getchar();}
	return x*f;
}

#define mm 50
int a[mm] ;

int mpow(int a , int b){
	int ans = 1 ;
	while(b){
		if(b & 1)
			ans = ans * a ;
		a = a * a ;
		b >>= 1 ;
	}
	return ans ; 
}

int ans[mm] ;
int cnt = 0 ;

int main(){
	freopen("power.in" , "r" , stdin) ;
	freopen("power.out" , "w" , stdout) ;
	int n = read() ;
	for(int i = 1 ; i <= 24 ; ++i){
		a[i] = mpow(2 , i) ;
	}
	for(int i = 24 ; i >= 1 ; --i){
		if(n >= a[i]) n -= a[i] , ans[++cnt] = a[i] ;
		else continue ;
	}
	if(n != 0){printf("-1") , putchar('\n') ; return 0 ;}
	for(int i = 1 ; i <= cnt ; ++i){
		printf("%d " , ans[i]) ;
	}
	return 0 ; 
}
