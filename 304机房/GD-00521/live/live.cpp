#include<bits/stdc++.h>
using namespace std;
int n,a[114515],w,pain[621];
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	scanf("%d%d",&n,&w);
	for(int i=1,x,j;i<=n;i++){
		int t=0;
		scanf("%d",&x);
		pain[x]++;
		for(j=600;j>=0&&t<max(i*w/100,1);j--){
			t+=pain[j];
		}
		printf("%d ",j+1);
	}
	
}
