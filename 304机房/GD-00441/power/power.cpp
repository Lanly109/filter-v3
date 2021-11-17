#include <iostream>
#include <cstdio>
using namespace std;
int n,cnt,ans[50];
int read(){
	int x = 0;
	char c = getchar();
	while(c < '0' || c > '9') c = getchar();
	while(c >= '0' && c <= '9') x = x * 10 + (c ^ 48),c = getchar();
	return x;
}
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	n = read();
	if(n & 1){
		printf("-1\n");
		return 0;
	}
	n >>= 1;
	for(int i = 2; n; i <<= 1){
		if(n & 1) ans[++cnt] = i;
		n >>= 1;
	}
	for(int i = cnt; i >= 1; i --) printf("%d ",ans[i]);
	return 0;
}
