#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int n,cnt=0;
	scanf("%d",&n);
	if(n%2){
		printf("-1");
		return 0;
	}
	bool v[111];
	n>>=1;
	for(int i=1;n;++i){
		if(n&1){
			v[i]=1;
			cnt=i;
		}
		n>>=1;
	}
	cnt++;
	while(cnt--){
		if(v[cnt])printf("%d ",int(pow(2,cnt)));
	}
} 
