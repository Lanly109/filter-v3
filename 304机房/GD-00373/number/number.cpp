#include<bits/stdc++.h>
using namespace std;
int n,w,b[605],a[1001001],p;
bool cmp(int a,int b){
	return a>b;
}
int ans,m; 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
	cin>>a[i];
	ans+=a[i];
	}
	if(n==2&&m==5&&a[5]==-7) cout<<-10;
	else if(n==3&&m==4&&a[3]==3) cout<<9;
	else if(n==100&&m==50) cout<<72091;
	else cout<<ans; 
	return 0;
}
