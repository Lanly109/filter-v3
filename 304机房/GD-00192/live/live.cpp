#include<cstdio>
using namespace std;
int sc[611];
int main(){
	register int n,w,num,j,a;
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	scanf("%d%d",&n,&w);
	scanf("%d",&a);
	++sc[a];
	printf("%d ",a);
	for(register int i=2;i<=n;++i){
		scanf("%d",&a);
		num=i*w/100;
		++sc[a];
		j=600;
		for(;sc[j]<num;--j)num-=sc[j];
		printf("%d ",j);
	}	
}
