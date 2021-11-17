#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001][1001],ans=-100000000;
int t[3][2]={{1,0},{0,1},{-1,0}};
bool g[1001][1001];
bool lei(int x,int y){
	return (x>0 && y>0 && x<=n && y<=m && !g[x][y]);
}
void f(int r,int c,int k){
	if(r==n && c==m){
		if(k>ans) ans=k;
		return;
	}
	g[r][c]=true;
	int i,r1,c1;
	for(i=0;i<3;i++){
		r1=r+t[i][0];
		c1=c+t[i][1];
		if(lei(r1,c1)){
			f(r1,c1,k+a[r1][c1]);
		}
	}
	g[r][c]=false;
}
int main(){
	ifstream fin("number.in");
	ofstream fout("number.out");
	fin>>n>>m;
	int i,j;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			fin>>a[i][j];
			g[i][j]=false;
		}
	f(1,1,a[1][1]);
	fout<<ans<<endl;
	return 0;
}
