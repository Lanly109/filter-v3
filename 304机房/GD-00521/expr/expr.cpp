#include<bits/stdc++.h>
using namespace std;
char s[1000021];
int n,q,tmp,a[100021],res;
int zh[100021];
void count(){
	int r=0,t1,t2;
	for(int i=1;i<=tmp;i++){
		if(s[i]=='x'){
			int j;t1=0;
			for(j=i+1;isdigit(s[j]);j++)
				t1=t1*10+s[j]-'0';
			zh[++r]=a[t1];
			i=j;
		}
		else{
			switch(s[i]){
				case '!':{
					zh[r]^=1;
					break;
				}
				case '&':{
					zh[r-1]&=zh[r];
					zh[r]=0;
					r--;
					break;
				}
				case '|':{
					zh[r-1]|=zh[r];
					zh[r]=0;
					r--;
					break;
				}
			}
		}
	}
	printf("%d\n",zh[r]);
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	while(s[tmp]!='\n'){
		s[++tmp]=getchar(); 
	}
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	cin>>q;
	for(int orz=1,x;orz<=q;orz++){
		memset(zh,0,sizeof(zh));
		scanf("%d",&x);
		a[x]^=1;
		count();
		a[x]^=1;
	}
}
