#include<cstdio>
#include<algorithm>
using namespace std;

int n, i;

int main(){
	freopen("power.in", "r", stdin);
	freopen("power.out", "w", stdout);
	scanf("%d", &n);
	if(n % 2){
		printf("-1");
		return 0;
	}
	for(i = 2; i <= n; i = i << 1);
	i = i >> 1;
	for( ; i >= 2; i = i >> 1){
		if(n >= i){
			n -= i;
			printf("%d ", i);
		}
	}
	return 0;
}
