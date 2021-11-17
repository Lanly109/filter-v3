#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
int n,m;
ll a[1010][1010],f[1010][1010];
void change(int y,int x){
	++y;
	f[x][y]=max(f[x][y],f[x][y-1]+a[x][y]);
	int t=f[x][y-1]+a[x][y];
	for(int i=x-1;i>=1;i--){
		f[i][y]=max(f[i][y],t+a[i][y]);
		t+=a[i][y];
	}
	t=f[x][y-1]+a[x][y];
	for(int i=x+1;i<=n;i++){
		f[i][y]=max(f[i][y],f[i-1][y]+a[i][y]);
		t+=a[i][y];
	}
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=-999999999999999999;
		}
	}
	for(int i=1;i<=n;i++){
		f[i][1]=f[i-1][1]+a[i][1];
	}
	for(int j=1;j<m;j++){
		for(int i=1;i<=n;i++){
			change(j,i);
		}
	}
	printf("%lld",f[n][m]);
	return 0;
}
