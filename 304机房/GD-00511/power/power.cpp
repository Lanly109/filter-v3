#include<bits/stdc++.h>
using namespace std;
inline void Read(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
}
inline void Close(){
	fclose(stdin);
	fclose(stdout);
}
long long dabiao[101]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608};
int main(){
	Read();
	long long n;
	cin>>n;
	if(n%2!=0||n==0){
		cout<<"-1";
		Close();
		return 0;
	}
	for(int i=23;i>=1;--i)
		if((n-dabiao[i])>=0){
			n-=dabiao[i];
			cout<<dabiao[i]<<" ";
		}
	Close();
	return 0;
}
