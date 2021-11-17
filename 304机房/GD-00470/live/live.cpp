#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;
int n,w;
int p[100005];
inline int read(){
	int ans=0,sym=1;
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
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	n=read();
	w=read();
	for(int i=1;i<=n;++i){
		p[i]=read();
		sort(p+1,p+i+1,cmp);
		printf("%d ",p[max(1,(int)floor(1.0*i*w/100))]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*10 30
100 100 600 100 100 100 100 100 100 100
*/
