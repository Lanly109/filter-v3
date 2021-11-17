#include<bits/stdc++.h>
using namespace std;
long long sum=0,n,m;
long long a[1005][1005];
int number(long i,long j){
	if(j==m-1&&i==n-1){
		return sum;
	}else{
		sum+=a[i][j];
		if(i!=n-1&&j!=m-1){
			sum+=max(number(i,j+1),number(i+1,j));
		}
		if(i==n-1){
			sum+=number(i,j+1);
		}
		if(j==m-1){
			sum+=number(i+1,j);
		}
	}
}
int main(){
	freopen("numbew.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}
	cout<<number(0,0);
	return 0;
}
