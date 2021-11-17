#include<bits/stdc++.h>
using namespace std;
int n,w;
int p[100005],a[610];

int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	
	cin>>n>>w;
	int wn=1;
	for(int i=0;i<=610;i++){
		a[i]=0;
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
		a[p[i]]++;
		wn=i*w/100;
		if(wn<1){
			wn=1;
		}
		for(int j=605;j>=0;j--){
			wn-=a[j];
			if(wn<=0){
				cout<<j<<" ";
				break;
			}
		}
	}
	

	return 0;
}
