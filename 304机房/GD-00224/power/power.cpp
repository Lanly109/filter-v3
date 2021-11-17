#include<cstdio>
#include<iostream>
using namespace std;
int n,cnt=0;
int a[100];
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	scanf("%d",&n);
	if(n%2==1){
		printf("-1");
		return 0;
	}
	while(n){
		int k=1;
		while((k<<1)<=n) k<<=1;
		a[++cnt]=k;
		n-=k;
	}
	for(int i=1;i<=cnt;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
