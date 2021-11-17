#include<iostream> 
#include<cmath> 
#include<cstring> 
#include<string> 
#include<cstdio> 
using namespace std;
int xn,ym;
int a[1001][1001];
bool b[1001][1001];
int cnt=-111100;
void dfs(int x,int y,int z){
	if(x>xn||y>ym){
		return ;
	}
	if(x==xn&&y==ym){
		if(z>cnt){
			cnt=z;
		}
		return ;
	}
    if(!b[x][y+1]){
		b[x][y+1]=true;
    	dfs(x,y+1,z+a[x][y+1]);
    	b[x][y+1]=false;
    }
    if(!b[x-1][y]){
		b[x-1][y]=true;
    	dfs(x-1,y,z+a[x-1][y]);
    	b[x-1][y]=false;
    }
    if(!b[x+1][y]){
    	b[x+1][y]=true;
    	dfs(x+1,y,z+a[x+1][y]);
    	b[x+1][y]=false;
    }
	return ;

}
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    cin>>xn>>ym;
    for(int i=1;i<=xn;i++) {
    	b[i][0]=true;
    	b[i][ym+1]=true; 
    	for(int j=1;j<=ym;j++){
    		b[0][j]=true;
    		b[xn+1][j]=true;
    		cin>>a[i][j];
		}
	}
	dfs(1,1,a[1][1]);
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
