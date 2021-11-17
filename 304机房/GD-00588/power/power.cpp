#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int n,m;
int t[1001];
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n;
	if(n<=0){
		cout<<-1;
			fclose(stdin);
			fclose(stdout);
		return 0;
	}
	m=n;
	int k=n;
	int temp=1;
	while(temp<n){
		temp *= 2;
	}
	int j=0;
	while(temp>1){
		if(temp <= m){
			m-=temp;
			t[++j] = temp;
		}
		temp/=2;
	}
	if(m>0){
		cout<<"-1";
	}
	else{
		for(int i=1; i<=j; i++){
			cout<<t[i]<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

