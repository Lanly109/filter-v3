#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int a[26];
	int n;
	scanf("%d",&n);
	if(n%2!=0){
		cout<<-1;
		return 0;
	}
	int p=2,z=1;
	a[0]=2;
	while(p<10000000){
		p*=2;
		a[z]=p;
		z++; 
	}
	int w;
	int s[26]={0};
	for(int i=0;i<26;i++){
		if(a[i]>n){
			w=i-1;
		}
	}
	int x=0;
	for(int i=w;i>=0;i--){
		if((n>a[i])||(n==a[i])){
			n-=a[i];
			s[x]=a[i];
			x++;
		}		
	}
	if(n==0){
		for(int i=0;i<26;i++){
			if(s[i]){
				cout<<s[i]<<" ";
			}
		}
	}
	if(n<0){
		cout<<-1;
	}

	return 0;
} 
