#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,w;
int a[100002];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	cin>>n>>w;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		sort(a+1,a+i+1,cmp);
		cout<<a[max(1,i*w/100)]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

