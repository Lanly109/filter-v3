#include<iostream> 
#include<cmath> 
#include<cstring> 
#include<string> 
#include<cstdio> 
#include<algorithm> 
using namespace std;
int n,w;
int a[100001];
int fs;
bool cmp(int a,int b){
	if(a>=b){
		return true;
	}
	return false;
}
int main (){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	cin>>n>>w;
	cin>>a[1];
	cout<<a[1]<<" ";
	for(int i=2;i<=n;i++){
		cin>>a[i];
		sort(a+1,a+i+1,cmp);
		fs=(i*w)/100;
		cout<<a[fs]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
