#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[30];
int c[30]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912};

void Cout(){
	for(int i=m-1;i>=0;i--) if(a[i]){
		printf("%d ",c[i]);
	}
	cout<<endl; 
}

void work(int x){
	while(x){
		if(x%2) a[m]=1;
		m++;
		x/=2;
	}
	Cout();
}

int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	scanf("%d",&n);
	if(n%2) printf("-1");
	else work(n);
	return 0;
} //Ta&Shan?Zhi@Shi%
