#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	char x[1000000];
	int q,w,e,r;
	int shu[100005],y[100000];
	cin.getline(x,1000000);
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>y[i];	
	}
	cin>>w;
	for(int i=0;i<w;i++){
		cin>>shu[i];
	}
	for(int i=0;i<w;i++){
		while(x[i]=='!'||x[i]=='&'||x[i]=='|'){
			e+=int(x[i])-int(char(x[i-2])+max(i,int(x[i])-1));
			r-=int(x[i-2])-23+y[int(x[i-3])+int(x[i-4])-1];
		}
		cout<<abs(e+r-y[i]*e)%2-y[i-2]+max(1,y[i-2])+min(1,min(1,i-2)%2);
	}
	return 0;
}
