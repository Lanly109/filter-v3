#include<iostream>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
int n,cnt=0,a[10000005];
queue<int> q;
bool c=true;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	scanf("%d",&n);
	if(n%2==1){
		printf("-1");
		return 0;
	}else{
		int p=n,y=0;
		while(p!=0){
			p/=2;
			y++;
		}
		a[0]=1,a[1]=2,a[2]=4;
		for(int i=3;i<=10000000;i++){
			a[i]=a[i-1]*2;
		}
		for(int i=y;i>=1;i--){
			if(cnt+a[i]<=n){
				cnt+=a[i];
				q.push(a[i]);
			}
		}
		while(!q.empty()){
			int k=q.front();
			q.pop();
			printf("%d ",k);
		}
		return 0;
	}
} 
