#include <bits/stdc++.h>

using namespace std;

int n;
int m[100005];
int mi;

int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin >> n;
	if(n % 2 != 0){
		printf("-1");
		return 0;
	}
	
	int i = 1;
	while(i <= n){
		i = i << 1;
	}
	i = i >> 1;
	
	for(;i > 1;i = i >> 1){
		if(n < i)continue;
		if(n == i){
			for(int j = 1;j <= mi;j++){
				printf("%d ",m[j]);
			}
			printf("%d",i);
			return 0;
		}
		n -= i;
		m[++mi] = i;
	}
	
	printf("-1");
	
	return 0;
} 
