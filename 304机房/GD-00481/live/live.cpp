#include <bits/stdc++.h>
#include <queue>

using namespace std;

int a[1000010]; 
int n,m;

int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		a[i]=-a[i];
		int j=max(1,i*m/100);
		sort(a+1,a+i+1);
		printf("%d ",-a[j]);
	}
	return 0;
} //Ta&Shan?Zhi@Shi%
