#include<iostream>
#include<cstring>

using namespace std;
int n,w;
int line;
int sc[100010];
int rank[610];
int main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	cin>>n>>w;
	memset(sc,0,sizeof(sc)); 
	memset(rank,0,sizeof(rank));
	for(int i=0;i<n;i++){
		cin>>sc[i];
	}
	for(int i=0;i<n;i++){
		int num=max(1,(i+1)*w/100);
		rank[sc[i]]++;
		int j=600;
		while(j>=0){
			if(num<=rank[j])break;
			num-=rank[j];
			j--;
		}
		cout<<j<<" ";
	}
	return 0;
}
