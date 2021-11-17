#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	int a,b,c,d,e,f;
	char n[100000];
	int m[10000];
	cin.getline(n,100000);
	cin>>a;
	for(int i=0;i<a;i++) cin>>m[i];
	cin>>b;
	for(int i=0;i<b;i++){
		cin>>c;
		f=0;
		while(n[i]=='|'||n[i]=='&'||n[i]=='!'){
			d+=int(n[i])-int(char(n[i-2])+max(i,int(n[i])-11)-1);
			e-=int(n[i-2])-23+m[int(n[i-3])+int(n[i-4])-1];
			i++;
			f++;
		}
		i-=f;
		cout<<abs(abs(d+e-m[i]*d)%2-m[i-2]+min(1,m[i-2]))%2;
	}
}
