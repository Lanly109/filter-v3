#include<iostream>
#include<cstdio>
using namespace std;
int n,m,c[100000],shu=1;
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int o=1;o<=i;o++){
			if(o==i){
				c[i]=x;
				break;
			}
			if(x>=c[o]){
				int j=o,a;
				while(j<=i){
					a=c[j];
					c[j]=x;
					j++;
					x=a;
				}
				break;
			}
		}
		int r=i*m/100;
		if(i*m<100)r++;
		cout<<c[r]<<" ";
	}
	return 0;
}  
