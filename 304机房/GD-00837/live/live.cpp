#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int n,w,len,gl;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sort(a,a+i+1,cmp);
		gl=max(1,(i+1)*w/100);
		cout<<a[gl-1]<<' ';
	}
	
	return 0;
}
