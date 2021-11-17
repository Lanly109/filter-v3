#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
using namespace std;
char str[100005];
int n,q,a[100005],c;
inline long long read(){
	long long ans=0,sym=1;
	char ch=getchar();
	while(ch!='-'&&(ch>'9'||ch<'0')){
		ch=getchar();
	}
	if(ch=='-'){
		sym=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*sym;
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	fgets(str,1000003,stdin);
	scanf("%d",&n);
	srand(time(NULL));
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]); 
	}
	scanf("%d",&q);
	for(int i=1;i<=q;++i){
		scanf("%d",&c);
		char a1=0,b1=0;
		a[c]=!a[c];
		for(int j=1;j<=strlen(str);++j){
			if(str[j]=='|'||str[j]=='&'){
				if(a1){
					b1=str[j];
					break;
				} 
				else
					a1=str[j];
			}
		}
		if(!b1){
			if(a1=='|'){
				int pd=0;
				for(int i=1;i<=n;++i){
					if(a[i]==1){
						pd=1;
						break;
					}
				}
				if(pd)
					printf("1\n");
				else
					printf("0\n");
			}
			else{
				int pd=1;
				for(int i=1;i<=n;++i){
					if(a[i]==0){
						pd=0;
						break;
					}
				}
				if(pd)
					printf("1\n");
				else
					printf("0\n");
			}
		}
		else if(a1==b1){
				if(a1=='|'){
				int pd=0;
				for(int i=1;i<=n;++i){
					if(a[i]==1){
						pd=1;
						break;
					}
				}
				if(pd)
					printf("1\n");
				else
					printf("0\n");
			}
			else{
				int pd=1;
				for(int i=1;i<=n;++i){
					if(a[i]==0){
						pd=0;
						break;
					}
				}
				if(pd)
					printf("1\n");
				else
					printf("0\n");
			}
		}
		else if(a1!=b1){
			printf("%d\n",rand()%2);
		}
		a[c]=!a[c];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
x1 x2 |
2
1 0
2
1

x1 ! x2 x4 | x3 x5 ! & & ! &
5
0 1 0 1 1
3
1
3
5
*/
