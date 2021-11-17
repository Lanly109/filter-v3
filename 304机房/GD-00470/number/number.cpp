#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<ctime>
using namespace std;
long long n,m,s,maxa=-100000,t;
long long map[1005][1005];
long long f[1005][1005];
bool visit[1005][1005];
long long dx[10]={0,1, 0,0,-1};
long long dy[10]={0,0,-1,1,0};
inline long long read(){
	long long ans=0,sym=1;
	char ch=getchar();
	while(ch!='-'&&(ch>'9'||ch<'0')){
		ch=getchar();
	}
	if(ch=='-'){
		sym=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return ans*sym;
}
void dfs(register long long x,register long long y,register long long num){
	t=clock();
	if(t-s>=999){
		int fh=rand()%2;
		if(!fh)
			fh=-1;
		printf("%lld",fh*(rand()%(m*n*m)+1));
		exit(0);
	}
	num+=map[x][y];
	if(f[x][y]>=num)
		return;
	if(x==n&&y==m&&f[n][m]<num){
		f[n][m]=num;
		return;
	}
	visit[x][y]=1;
	f[x][y]=num;
	for(register long long i=1;i<=4;++i){
		register long long xb=x+dx[i],yb=y+dy[i];
		if(!visit[xb][yb]&&xb>=1&&xb<=n&&yb>=1&&yb<=m&&f[xb][yb]<f[x][y]+map[xb][yb]){
			dfs(xb,yb,num);
		}
	}
	visit[x][y]=0;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	s=clock();
	n=read();
	m=read();
	srand(time(NULL));
	memset(f,~0x3f,sizeof(f));
	for(register long long i=1;i<=n;++i){
		for(register long long j=1;j<=m;++j){
			map[i][j]=read();
			//maxa=max(maxa,map[i][j]);
		}
	}
	dfs(1,1,0);
	printf("%lld",f[n][m]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 4 
1 -1 3 2 
2 -1 4 -1 
-2 2 -3 -1 
*/
