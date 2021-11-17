#include<bits/stdc++.h>
using namespace std;
int n,a[121],tmp,t=1;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	scanf("%d",&n);
	if(n&1!=0){
		printf("-1");
		return 0;
	}
	else{
		while(n>0){
			a[++tmp]=n&1;
			t*=2;
			n>>=1;
		}
		t/=2;
		for(int i=tmp;i>=1;i--,t/=2){
			if(a[i])
				printf("%d ",t);
		}
	}
}
