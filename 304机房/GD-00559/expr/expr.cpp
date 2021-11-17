#include<bits/stdc++.h>
using namespace std;
char s[1000005];
int q,n,qq;
const int M=100005;
bool x[M]={},xn[M]={};
int st[M]={},l,r;
int a[M]={},ai;
int cnt=0;
int ans[M]={};
int anss;

/*bool ex(){
	for(int i=0;i<j;i++){
		while(st[i]>0){
			i++;
		}
		if(st[i]==-1){
			ans[i]=xn[st[i-2]]&xn[st[i-1];
		}
		if(st[i]==-2){
			ans[i]=xn[st[i-2]]|xn[st[i-1]];
		}
		if(st[i]==-3){
			ans[i]=!xn[st[i-1]];
		}
	}
}
*/
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	
	gets(s);
	int j=0;
	for(int i=0;i<M;i++){
		st[i]=0;
	}
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='x'){
			i++;
			ai=1;
			while(s[i]>='0'&&s[i]<='9'){
				a[ai]=s[i]-'0';
				ai++;
				i++;
			}
			for(int k=1;k<=ai;k++){
				st[j]+=a[k]*pow(10,k-1);
			}
			j++;
		}
		if(s[i]=='&'){
			st[j]=-1;
			j++;
		}
		if(s[i]=='|'){
			st[j]=-2;
			j++;
		}
		if(s[i]=='!'){
			st[j]=-3;
			j++;
		}
		
	}
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	cin>>q;
	for(int i=0;i<q;i++){
		for(int k=0;k<j;k++){
			xn[k]=x[k];
		}
		for(int p=0;p<j;p++){
			if(st[p]>0){
				ans[p]=xn[st[p]];
			}
			if(st[p]<0){
				ans[p]=st[p];
			}
		}
		cin>>qq;
		ans[qq]=!ans[qq];
		for(int i=0;i<j;i++){
			while(ans[i]>0){
				i++;
			}
			r=i;
			while(ans[r]<=0){
				r--;
			}
			l=r-1;
			if(st[i]==-1){
				ans[i]=ans[l]&ans[r];
			}
			if(st[i]==-2){
				ans[i]=ans[l]|ans[r];
			}
			if(st[i]==-3){
				ans[i]=!ans[r];
			}
			anss=i;
		}
		cout<<ans[anss]<<endl;
	}
	
	return 0;
}
