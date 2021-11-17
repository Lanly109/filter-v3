#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n;
	if(n%2){
		cout<<-1;
	}
	else{
		int a=pow(2,(int)log2(n));
		while(n>0){
			if(n>=a){
				cout<<a<<' ';
				n-=a;
			}
			a>>=1;
		}
	}
	return 0;
}
