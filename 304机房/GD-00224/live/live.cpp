#include<cstdio>
#include<iostream>
using namespace std;
int n,w;
int a[100010],b[100010],book[610];
int main()
{
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		b[i]=max(1,i*w/100);
	}
	for(int i=1;i<=n;++i){
		++book[a[i]];
		int sum=0;
		for(int j=600;j>=0;--j){
			if(sum+book[j]<b[i]) sum+=book[j];
			else{
				printf("%d ",j);
				break;
			}
		}
	}
	return 0;
}
