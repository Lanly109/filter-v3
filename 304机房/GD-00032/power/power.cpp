#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
vector<int> v;
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	int n;
	cin>>n;
	int i=1;
	int x=2;
	for(;x<=n;i++,x*=2);
	for(int j=i;j>=1;j--){
		if(n>=pow(2,j)){
		    n-=pow(2,j);
		    v.push_back(pow(2,j));
	    }
	}
	if(n!=0){
		cout<<-1<<endl;
		return 0;
	}
	else{
		for(int k=0;k<v.size();k++){
			cout<<v[k]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
