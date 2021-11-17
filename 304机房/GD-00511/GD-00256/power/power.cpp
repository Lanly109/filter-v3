#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("power.in");
	ofstream fout("power.out");
	int n;
	fin>>n;
	if(n%2==1){
		fout<<-1<<endl;
		return 0;
	}
	int a[30],i,j;
	a[0]=1;
	for(i=1;i<=30;i++) a[i]=2*a[i-1];
	for(i=30;i>0;i--){
		if(n-a[i]>=0){
			fout<<a[i]<<' ';
			n=n-a[i];
		}
		if(n==0) return 0;
	}
	return 0;
}
