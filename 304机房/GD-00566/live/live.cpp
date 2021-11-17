#include<bits/stdc++.h>
using namespace std;
int n,w,sum[1000],x,ans[100005];
void change(int s){
	while(s<=601){
		sum[s]++;
		s+=(s&-s);
	}
}
int query(int s){
	int res=0;
	while(s>0){
		res+=sum[s];
		s-=(s&-s);
	}
	return res;
}
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	cin>>n>>w;
	for(int i=1;i<=n;i++){
		scanf("%d",&x);
		int now=max(i*w/100,1);
		change(601-x);
		int l=0,r=600;
		while(l<r){
			int mid=(l+r+1)/2;
			if(query(601-mid)>=now) l=mid;
			else r=mid-1;
		}
		ans[i]=l;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
