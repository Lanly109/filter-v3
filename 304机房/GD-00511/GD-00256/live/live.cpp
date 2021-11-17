#include<bits/stdc++.h>
using namespace std;
int n,w,a[100001];
int main(){
	ifstream fin("live.in");
	ofstream fout("live.out");
	fin>>n>>w;
	int i,j,w1,s,aii,ai;
	for(i=1;i<=n;i++) fin>>a[i];
	for(i=1;i<=n;i++){
		w1=i*w/100;
		ai=i;
		s=max(1,w1);
		for(j=i-1;j>0;j--){
			if(a[ai]>a[j]){
				aii=a[ai];
				a[ai]=a[j];
				a[j]=aii;
				ai=j;
			}
			//if(j<s) break;
			else break;
		}
		fout<<a[s]<<' ';
	}
	fout<<endl;
	return 0;
}
