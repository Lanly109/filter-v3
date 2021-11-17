#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	int n,w;
	cin>>n>>w;
	int a[100005];
	int r;
	int x;
	int b[100005]={0};
	int m=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]); 
	}
	for(int i=1;i<=n;i++){
		r=max(1,i*w/100);
		b[i]=a[i];
		sort(b,b+i+1);
		cout<<b[i-r+1]<<" ";
	}
	
	return 0;
}
