#include<bits/stdc++.h>
using namespace std;
multiset<int> s;
int n,w,p,l=0;
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	scanf("%d %d",&n,&w);
	for(int i=1;i<=n;i++){
		l++;
		int x;
		scanf("%d",&x);
		s.insert(x);
		p=max(1,(l*w)/100);
		multiset<int>::iterator t;
		t=s.begin();
		for(int cnt=1;cnt<=l-p;cnt++) t++;
		printf("%d ",*t);
	}
}
