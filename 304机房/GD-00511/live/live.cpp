#include<bits/stdc++.h>
using namespace std;
int n,w,a[100001];
bool cmp(int a,int b){ return a>b; }
inline void Read(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
}
inline void Close(){
	fclose(stdin);
	fclose(stdout);
}
int main(){
	Read();
	cin>>n>>w;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		sort(a+1,a+i+1,cmp);
		int k=max(1,(int)(i*w/100));
		cout<<a[k]<<" ";
	}
	Close();
	return 0;
}
