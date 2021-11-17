#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm> 
using namespace std;

int n,w;
int ct[650]={0};
int point(int p,int w){
	int s=max(1.0,floor(p*w/100.0));
	int cnt=0,ans;
	for(int i=600;i>=0;i--){
		cnt+=ct[i];
		if(cnt>=s){
			ans=i;
			break;
		}
	}
	printf("%d ",ans);
}
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	int tmp,p=0;
	scanf("%d %d",&n,&w);
	for(int i=1;i<=n;i++){
		scanf("%d",&tmp);
		ct[tmp]++;
		p++;
		point(p,w);
	}
	printf("\n");
	return 0;
}
