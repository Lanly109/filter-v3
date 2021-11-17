#include<cstdio>
#include<algorithm>
using namespace std;
int n,w,live[100005];
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	scanf("%d %d", &n, &w);
	for(int i=0;i<n;++i){
		int x,line,t,ans;
		scanf("%d",&x);
		line = max(1,(int)((i + 1) * (w / 100.0)));
		for(int j=0;j<=i;j++){
			if(x >= live[j]){
				t = live[j];
				live[j] = x;
				x = t;
			}
			if(j+1 == line){
				ans = live[j];
			}
		}
		if(i)printf(" ");
		printf("%d",ans);
	}
	return 0;
}
