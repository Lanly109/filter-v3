#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm> 
using namespace std;

int n,w;
bool grid[1005][1005]={{0}};
int vals[1005][1005]={0};
long long f(int x,int y){
	printf("%d %d\n",x,y);
	if(x==1 && y==1){
		return vals[1][1];
	}else{
		int max=-2e9,maxi,maxj;
		for(int i=-1;i<=1;i++){
			for(int j=-1;j<=1;j++){
				if(((i!=0 && j==0) || (i==0 && j!=0)) && grid[x+i][y+j] && max<f(x+i,y+j)){
					max=f(x+i,y+j);
					maxi=i;
					maxj=j;
				}
			}
		}
		grid[x+maxi][y+maxj]=false;
		return max+vals[x][y];
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d %d",&n,&w);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=w;j++){
			scanf("%d",&vals[i][j]);
			vals[i][j]=1;
		}
	}
	printf("%d",f(n,w));
	return 0;
}
