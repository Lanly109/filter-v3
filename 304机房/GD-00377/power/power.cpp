#include<cstdio>
int ans[23];
int n;
int log2(int t){
	int cnt = 0;
	while(t > 1){
		t >>= 1;
		cnt++;
	}
	return cnt;
}
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	scanf("%d",&n);
	if(n & 1){
		printf("-1");
	}
	int cnt = 0;
	for(int i = log2(n);i >= 1;i--){
		int t = 1 << i;
		if(t <= n){
			ans[cnt++] = i;
			n -= t;
		}
	}
	for(int i = 0;i < cnt;i++){
		if(i) printf(" ");
		printf("%d",ans[i]);
	}
	return 0;
} 
