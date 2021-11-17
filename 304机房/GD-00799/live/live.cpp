#include<bits/stdc++.h>
using namespace std;
int n,w,np;
int a[100007],st[100007],cnt[607];
vector<int> now;
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;++i){
		np=max(1,i*w/100);
		sort(a+1,a+i+1);
		printf("%d ",a[i-np+1]);
//		for(int j=1;j<=i;++j){
//			cout<<a[j]<<" ";
//		}
//		printf(" %d %d\n",a[i-np+1],np);
//		cout<<np<<" ";
	}
	return 0;
} 
