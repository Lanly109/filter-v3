#include<bits/stdc++.h>
using namespace std;
int p[20];
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	long long a,b,c,d;
	cin>>a;
	if(a%2==1){
		cout<<-1;
		return 0;
	}
	b=0;
	while(a>0){
		p[b]=a%2;
		a-=p[b];
		b++;
		a/=2;
	}
	d=pow(2,b);
	for(int i=b;i>0;i--){
		c=p[i]*d;
		if(c!=0) cout<<c<<" ";
		d/=2;
	}
	return 0;
} 
