#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	long long n,w,p=1;
	long long a[999999],b[999999];
	cin>>n,w;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=0;j<n;j++){
			b[i]=a[i];
		}
		 long long x=max(p,(i+1)*w/100);
		sort(b,b+x);
		cout<<b[x]<<" ";
	}
	return 0;
}
