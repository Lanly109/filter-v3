#include<bits/stdc++.h>
using namespace std;
int n,b;
int ans[100]={};
int cnt;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);

	cin>>n;
	if(n%2==1){
		cout << "-1"<<endl;
		return 0;
	}
	b=2;
	cnt=0;
	while(b*2<=n){
		b*=2;
	}
	if(b==n){
		cout<<b;
		return 0;
	}
	for(int i=0;i<=100;i++){
		n-=b;
		if(n>=0){
			ans[i]=b;
			b/=2;
			cnt++;
		}
		if(n<0){
			break;
		}
	}
	if(cnt!=0){
		for(int i=0;i<cnt;i++){
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	if(cnt==0){
		cout<<"-1"<<endl;
	}

	return 0;
}
