#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath> 
using namespace std;
long long a[150000],n,w,s=100,b=1;
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	scanf("%lld %lld",&n,&w);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		sort(a+1,a+i+1);
		printf("%lld ",a[i+1-max(b,(i*w)/s)]);
	}
	return 0; 
} 
