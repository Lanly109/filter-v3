#include<bits/stdc++.h>
using namespace std;
static int p[100000];
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	long a,b,c,d,e;
	cin>>a>>b;
	cin>>p[0];
	cout<<p[0]<<" ";
	for(int i=1;i<a;i++){
		c=(i+1)*b/100;
		if(c==0) c=1;
		cin>>p[i];
		d=i;
		while(p[d]>p[d-1]&&d>0){
			e=p[d];
			p[d]=p[d-1];
			p[d-1]=e;
			d--;
		}
		cout<<p[c-1]<<" ";
	}
}
