#include <bits/stdc++.h>

using namespace std;

int n,w;
int a[100005];
int num;

void px(int len,int n){
	for(int i = len;i >= 1;i--){
		if(a[i] < n)a[i + 1] = a[i];
		else {
			a[i + 1] = n;
			return;
		}
	}
	a[1] = n;
}

int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	
	cin >> n >> w;
	
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		//sort(a + 1,a + i + 1,cmp);
		px(i - 1,a[i]);
		num = max(1,w * i / 100);
		printf("%d ",a[num]);
	}
	
	return 0;
} 
