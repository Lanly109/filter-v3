#include<iostream>
#include<cstdio>
using namespace std;
inline int getnumber(){
	int z=1,x=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')
			z=-1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar(); 
	}
	return z*x;
}
int n,w,bucket[610],k;
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	n=getnumber(),w=getnumber();
	for(int i=0;i<=605;i++)
		bucket[i]=0;
	for(register int i=1;i<=n;i++){
		k=getnumber();
		bucket[k]++;
		int now=0,m=max(1,int(i*w/100.0)),sc=0;
		for(register int j=601;j>=0;j--){
			if(now>=m)
				break;
			if(bucket[j]!=0){
				now+=bucket[j];
				sc=j;
			}
		}
		cout<<sc<<" ";
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
