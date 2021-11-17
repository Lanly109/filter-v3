#include<iostream>
#include<cstring>
#include<ctime>
using namespace std;
int n,m;
int s[1010][1010];
bool vis[1010][1010];
long long maxn[1010][1010];
long long dfs(int a,int b,long long v){
	//cout<<a<<" "<<b<<" "<<v<<endl; 
	if(a==-1||b==-1||a==n||b==m||vis[a][b])return 0x8f8f8f8f8f8f8f8f;
	v+=s[a][b];
	if(v<maxn[a][b])return 0x8f8f8f8f8f8f8f8f;;
	maxn[a][b]=v;
	if(a==n-1&&b==m-1){
		return v;
	}
	vis[a][b]=true;
	long long ans=0x8f8f8f8f8f8f8f8f;
	ans=max(ans,dfs(a-1,b,v));
	ans=max(ans,dfs(a+1,b,v));
	ans=max(ans,dfs(a,b+1,v));
	vis[a][b]=false;
	return ans;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	//cout<<"1 "; 
	memset(s,0,sizeof(s));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			//cout<<"1 ";
			cin>>s[i][j];
			//cout<<"1 "; 
		}
	}
	//cout<<"1 "; 
	memset(vis,0,sizeof(vis));
	memset(maxn,0x8f,sizeof(maxn));
	cout<<dfs(0,0,0)<<endl;
	return 0;
}
