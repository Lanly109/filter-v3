#include <bits/stdc++.h>

using namespace std;

int a[1010][1010];
int f[1010][1010];
int c[1010][1010];
bool used[1010][1010];
int n,m;

int helper(int x,int y){
	if(used[x][y]) return f[x][y];
	else return -10010;
}

int helper1(int x,int y){
	if(used[x][y]) return c[x][y];
	else return -10010;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d%d",&n,&m);
	//memset(f,-2147483648,sizeof(f));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
	f[1][1]=a[1][1];
	used[1][1]=true;
	c[1][1]=a[1][1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=1;j++){
			if(i==j&&i==1) continue;
			f[i][j]=a[i][j]+max(helper(i-1,j),helper(i,j-1));
			used[i][j]=true;
		}
	for(int j=2;j<=m;j++)
		for(int i=1;i<=n;i++) {
			c[i][j]=f[i][j-1]+a[i][j];
			used[i][j]=true;
			//if(i==3&&j==2) printf("%d %d\n",helper1(i,j)+a[i-1][j],f[i-1][j]);
			f[i][j]=a[i][j]+max(helper(i-1,j),helper(i,j-1));
			if(i!=1&&j!=m) f[i-1][j]=max(helper1(i,j)+a[i-1][j],f[i-1][j]);
		}
	
//	for(int i=n;i>0;i--)
//		for(int j=1;j<=m;j++) {
//			if(m==j&&i==n) continue;
//			f[i][j]=max(a[i][j]+max(helper1(i+1,j),helper(i,j-1)),helper(i-1,j));
//			used[i][j]=true;
//		}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) printf("%d ",f[i][j]);
//		cout<<endl;
//	}
//		
	printf("%d\n",f[n][m]);
	return 0;
} //Ta&Shan?Zhi@Shi%
	
