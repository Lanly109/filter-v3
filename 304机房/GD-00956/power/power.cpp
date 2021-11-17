#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm> 
using namespace std;

int n,cnt;
bool k[1000]={0};
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cnt=0;
	scanf("%d",&n);
	if(n%2==1){
		printf("-1\n");
	}else{
		while(n){
			if(n%2==1){
				k[cnt]=1;
			}
			n/=2;
			cnt++;
		}
	}
	for(int i=100;i>=1;i--){
		if(k[i]){
			printf("%d ",1<<i);
		}
	}
	return 0;
}
