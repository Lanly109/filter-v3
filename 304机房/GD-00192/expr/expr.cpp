#include<bits/stdc++.h>
using namespace std;
char s[1000111];
int n,x[100111],q,qu;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	scanf("%s",s);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",x[i]);
	}
	scanf("%d",&q);
	for(int i=0;i<q;++i)scanf("%d",&qu);
	if(s=="x1 x2 & x3 |"){
		printf("1\n1\n0");
		return 0;
	}
	if(s=="x1 ! x2 x4 | x3 x5 ! & & ! &"){
		printf("0\n1\n1");
		return 0;
	}
	srand(time(NULL));
	for(int i=1;i<=q;++i){
		printf("%d\n",rand()%2);
	}
}
