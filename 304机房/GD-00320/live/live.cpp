#include<bits/stdc++.h>

using namespace std ;

int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+(ch^'0');ch=getchar();}
	return x*f;
}

inline int max(int a , int b){return a > b ? a : b ;}

#define mm 650
int a[mm] = {0} ;

bool cmp(int a , int b){
	return a > b ;
}

int maxn = -1 ;

int main(){
	freopen("live.in" , "r" , stdin) ;
	freopen("live.out" , "w" , stdout) ;
	int n = read() , w = read() ;
	for(int i = 1 ; i <= n ; ++i){
		int m = read() ; a[m]++ ;
		maxn = max(maxn , m) ;
		int num = max(1 , i * w / 100) ;
//		printf("num : %d" , num) ;
		int tot = 0 ;
		for(int j = maxn ; j >= 1 ; --j){
			tot += a[j] ;
			if(tot >= num){
				printf("%d " , j) ;
				break ;
			}
		}
	}
	return 0 ;
}
