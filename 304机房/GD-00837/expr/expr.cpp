#include<bits/stdc++.h>
using namespace std;
string s;
char k[10000];
int c[10000];
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>c[i];
	int kl=1;
	int o=0;
	bool ol=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='&'||s[i]=='|'){
			k[kl++]=s[i];
		}
		if(c[i]=='!'){
			if(c[o]==0)c[o]=1;
			else c[o]=0;
		}
		if(s[i]!='!'&&s[i]!=' '&&s[i]!='&'&&s[i]!='|'){
			if(!ol){
				o++;
				ol=1;
			}
		}
		else ol=0;
	}
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int l;
		cin>>l;
		if(c[l]==1)c[l]=0;
		else c[l]=1;
		int j=0,h=c[1];
		while(1){
			j++;
			if(j==kl+1){
				break;
			}
			if(k[j]=='&'){
				if(h==1&&c[j+1]==1){
					h=1;
				}else h=0;
			}
			if(k[j]=='|'){
				if(h==1||c[j+1]==1){
					h=1;
				}else h=0;
			}
		}
		cout<<h<<endl;
		if(c[l]==1)c[l]=0;
		else c[l]=1;
	}
	return 0;
} 
