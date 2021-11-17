#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
int a[50]={2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,
32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216};
int main()
{
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int n;
	cin>>n;
	if(n%2==1){
		cout<<"-1";
		return 0;
	}
	for(int i=23;i>=0;i--){
		if(n>=a[i]){
			cout<<a[i]<<" ";
			n-=a[i];
		}
	}
	fclose(stdin);fclose(stdout);
	
	return 0;
} 
