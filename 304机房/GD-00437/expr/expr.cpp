#include<iostream> 
#include<cmath> 
#include<cstring> 
#include<string> 
#include<cstdio> 
using namespace std;
int n,q,q1[10001];
int ans[3]={};
int a1[10001];
string a;
void ws(int step){

	for(int i=1;i<a.length() ;i++){
		if(step==2){
			step=1;
		}
		if(a[i]<='9'&&a[i]>='0'){
			ans[++step]=a1[a[i]-'0'];
		}else if(a[i]=='&'){
			if(ans[1]&&ans[2]){
				ans[1]=1;
			}else{
				ans[1]=0;
			}
		}else if(a[i]=='|'){
			if(ans[1]||ans[2]){
				ans[1]=1;
			}else{
				ans[1]=0;
			}
		}else if(a[i]=='!'){
			if(ans[step]==1){
				ans[step]=0;
			}else{
				ans[step]=1;
			}
		}
	}
    cout<<ans[step]<<endl;
	return ;
}
int main (){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	getline(cin,a);
	cin>>n; 
	for(int i=1;i<=n;i++){
		cin>>a1[i];
	}
	cin>>q;
	
	for(int i=1;i<=q;i++){
		cin>>q1[i];
	}
	for(int i=1;i<=q;i++){
		if(a1[q1[i]]==1){
			a1[q1[i]]=0;
		}else{
			a1[q1[i]]=1;
		}
		ws(0);
		if(a1[q1[i]]){
			a1[q1[i]]=0;
		}else{
			a1[q1[i]]=1;
		}
	}	

	fclose(stdin);
	fclose(stdout);
	return 0;
}
