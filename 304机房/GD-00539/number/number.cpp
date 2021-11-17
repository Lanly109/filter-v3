#include<iostream>
#include<cstdio>
using namespace std;
int n,m,c[1000][1000],p[1000][1000],f[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int pan(int x,int y,int shu){
	
	if(p[x][y]==1){
		return shu;
	}
	shu=shu+c[x][y];
	cout<<c[x][y]<<" "<<shu<<"   "<<x<<" "<<y<<endl;

	
	if(x==n&&y==m){
		return shu;
	}
	p[x][y]=1;
	int d=shu;
	for(int i=0;i<4;i++){
		if(0<x+f[i][0]&&x+f[i][0]<=n&&0<y+f[i][1]&&y<=m){
//			cout<<a<<" "<<b<<endl;
			int e=shu+pan(x+f[i][0],y+f[i][1],shu);
			if(e>d){
				d=e;
			}

		}
	} 
	p[x][y]=0;
	
	return d;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int o=1;o<=m;o++){
			cin>>c[i][o];
		}
	}
	cout<<endl;
	int z=pan(1,1,0);
	cout<<z<<endl;
	return 0;
}  
