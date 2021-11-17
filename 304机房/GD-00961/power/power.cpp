#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,b;
double f,a[20050000];
void ans(int n){
	if(n%2){
		a[b]=f;
		b++;
	}
	f++;
	if(n/2==0)
	return ; 
	ans(n/2);
}

int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	
	cin>>n;
	if(n%2){
		cout<<"-1";
		return 0;
	} 
	ans(n);
	for(int i=b-1;i>=0;i--)
	printf("%.0lf ",pow(2,a[i]));
	return 0;
} 
