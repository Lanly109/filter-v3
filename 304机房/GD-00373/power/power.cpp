#include<bits/stdc++.h>
using namespace std;
int n,j=1,l;
int a[500],ans[500];
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n;
	for(int i=2;i<=n;i*=2,j++){
		a[j]=i;
	}
	for(int i=j;i>=1;i--){
		ans[++l]=a[i];
		n-=a[i];
		if(n<0){
		 n+=a[i];
		 l--;
		}	
	}
	if(n==0){
		for(int i=1;i<=l;i++){
			if(ans[i])
			cout<<ans[i]<<" ";
		}
	}
	else cout<<-1;
	return 0;
}
