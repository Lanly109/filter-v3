#include<cstdio>
using namespace std;
long long n,m,a[1005][1005],sum=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			scanf("%lld",&a[i][j]);
			sum+=a[i][j]; 
		}
	}
	printf("%lld",sum);
	return 0;
} 
