#include<bits/stdc++.h>
using namespace std;
int n,a[100006],b[605],w;
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	cin>>n>>w;
	 for(int i=1;i<=n;i++){
	 	cin>>a[i];
	 }
	 for(int i=1;i<=n;i++){
	 	b[a[i]]++;
	 	int x=max(1,i*w/100);
	 	for(int j=600;j>=0;j--){
	 		if(b[j]){
	 			x-=b[j];
	 			if(x<=0){
	 				cout<<j<<" ";
	 				break;
				 }
			 }
		 }
	 	
	 }
	return 0;
}
