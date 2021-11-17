#include<iostream> 
#include<cmath> 
#include<cstring> 
#include<string> 
#include<cstdio> 
using namespace std;
int n;
int a[100000];
bool find(int x,int step,int cnt){
	if(x==cnt){
		a[step++]=cnt;
		a[0]=step;
		return true;
	}
	if(cnt>x){
		return false;
	}
	if(find(x,step,cnt*2)){
		return true;
	}
	a[step++]=cnt;
	if(find(x-cnt,step,cnt*2)){
		return true;
	}
	return false;
}
int main (){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin>>n;
	if(n%2!=0){
		cout<<"-1";
	}else{
		if(find(n,1,2)){
		    for(int i=a[0]-1;i>=1;i--){
			    cout<<a[i]<<" " ;
		    }
	    }else{
		    cout<<"-1";
	    }
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
