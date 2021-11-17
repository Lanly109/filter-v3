#include<bits/stdc++.h>
using namespace std;
int n,w,a[100005];
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		a[i]=-a[i];
		sort(a+1,a+i+1);
		printf("%d ",-a[max(1,i*w/100)]);
	}
	return 0;
}
