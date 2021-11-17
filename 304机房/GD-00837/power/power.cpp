#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	long long n;
	cin>>n;
	if(n%2){
		cout<<-1;
		return 0;
	}
	while(1){
		double l=log(n)/log(2);
		long long d=2,z=int(l),ans=1;
		while(z!=1){
			if(z%2){
				ans*=d;
				z--;
				continue; 
			}
			d*=d;
			z/=2;
		}
		ans*=d;
		cout<<ans<<' ';
		if(l!=int(l)){
			n-=ans;
		}
		else break;
	}
	return 0;
} 
