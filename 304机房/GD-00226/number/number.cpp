#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e,ans=0;
static int m[1000][1000];
int next(int x,int y){
	if(x==a-1&&y==b-1) ans+=m[x][y];
	else{
		ans+=m[x][y];
		if(x!=a-1&&y!=b-1) ans+=max(next(x,y+1),next(x+1,y));
		else if(x-1==a) ans+=next(x,y+1);
		else if(y-1==b) ans+=next(x+1,y);
	}
	return ans;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a>>b;
	for(int i=0;i<a;i++) for(int j=0;j<b;j++) cin>>m[i][j];
    cout<<next(0,0);
}
