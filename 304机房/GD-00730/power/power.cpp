#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,k=1,c=0,num[10005];
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n;
	for(int i=0;i<=10005;i++)
		num[i]=0;
	while(1){
		if(k*2<=n)
			k*=2;
		else
			break;
	}
	for(int i=k;i>0;i--){
		if(n-pow(2,i)>=0){
			c++;
			num[c]=pow(2,i);
			n-=pow(2,i);
		}
	}
	if(n==0){
		for(int i=1;i<=c;i++)
			cout<<num[i]<<" ";
	}
	else
		cout<<"-1"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
