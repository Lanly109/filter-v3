#include<bits/stdc++.h>
using namespace std;
int n;
void find(int x,int s){
	if(x==0)return;
	find(x>>1,s+1);
	if(x&1)printf("%d ",1<<s);
}
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	scanf("%d",&n);
	if(n&1){
		puts("-1");
		return 0;
	}
	find(n>>1,1);
	return 0;
}
