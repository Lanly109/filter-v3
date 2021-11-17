#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,w,a[100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	cin>>n>>w;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sort(a,a+i);
		int k=(i+1)*w*0.01;
		cout<<a[i+1-max(1,k)]<<" ";
	}
	return 0;
} 
