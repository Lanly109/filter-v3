#include<bits/stdc++.h>
using namespace std;
int ans[107];
int n;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	memset(ans,0,sizeof(ans));
	scanf("%d",&n);
//	cout<<n<<endl<<endl;
	if(n%2==1){
		printf("-1");
		return 0;
	}
	int i=30;
	for(;i>=1;--i){
		if(n>=pow(2,i)){
	//		cout<<"yes";
			n=n-pow(2,i);
			ans[i]=1;
		}
	}

	for(i=30;i>=2;--i){
		if(ans[i]==1)
			cout<<pow(2,i)<<" ";
	}
	return 0;
} 
