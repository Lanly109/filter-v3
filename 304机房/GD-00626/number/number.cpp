#include<bits/stdc++.h> 
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n,m,a[500][500]={0},f[500][500]={0};
	cin>>n>>m;
	 for(int N=1;N<=n;N++)
	 {
	     for(int M=1;M<=m;M++)
	     {
		  cin>>a[N][M];
		  f[1][1]=a[1][1];
		 	f[N][M]=max(f[N-1][M],f[N][M-1])+a[N][M];
			} 
	 }
	 cout<<f[n][m];
	 return 0; 
}
