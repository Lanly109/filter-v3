#include<iostream>
#include<cstdio>
using namespace std;
int pan(int n){
	int shu=0;
	while(n!=1){
		
		if(n%2!=0){
			
			return 0;
		}
		n=n/2;
		shu++;
	}
	return shu;
}
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int n,x=1,m[10000];
	cin>>n;
	for(int i=n;i>0;i--){
		if(n-i>=0){
			int o=pan(i);
			if(o!=0){
				m[x]=o;
				x++;
				n=n-i;
			}
		}
	}
	if(n!=0){
		cout<<"-1";
		return 0;
	}
	for(int i=1;i<x;i++)cout<<m[i]<<" ";
	return 0;
}  
