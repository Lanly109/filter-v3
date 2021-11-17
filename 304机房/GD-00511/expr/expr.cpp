#include<bits/stdc++.h>
using namespace std;
inline void Read(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
}
inline void Close(){
	fclose(stdin);
	fclose(stdout);
}
bool q1[1000001];
char q2[1000001];
bool x[100001];
int main(){
	Read();
	string s;
	int n;
	getline(cin,s);
	cin>>n;
	for(int i=1;i<=n;++i) cin>>x[i];
	int q1_len=0,q2_len=0; 
	for(int i=0;i<=s.size();++i){
		if(s[i]=='x'){
			int k=0,sum=i+1;
			while(s[sum]>='0'&&s[sum]<='9'){
				k*=10;
				k+=(s[sum]-'0');
				sum++;
			}
			q1[++q1_len]=x[k];
			if(s[sum+1]=='!') q1[++q1_len]=!q1[++q1_len]; 
		}
		else if(s[i]=='|') q2[++q2_len]='|';
		else if(s[i]=='&') q2[++q2_len]='&';
		else if(s[i]=='!'&&!(s[i-2]>='0'&&s[i-2]<='9')) q2[++q2_len]='!';
	}
	int q;
	cin>>q;
	while(q--){
		int k,q1_fwd=1,q2_fwd=1;
		bool is=false;
		cin>>k;
		q1[k]=!q1[k];
		while((q2_fwd<=q2_len)){
			char tmp=q2[q2_fwd]; q2_fwd++;
			if(tmp=='!') is=true;
			if(tmp=='|'){
				bool flag=false;
				if(q1[q1_fwd]==0&&q1[q1_fwd+1]==0) flag=true,q1[q1_fwd+1]=0;
				if(!flag) q1[q1_fwd+1]=1;  
				q1_fwd++;
			} 
			else if(tmp=='&'){
				bool flag=false;
				if(q1[q1_fwd]==1&&q1[q1_fwd+1]==1) flag=true,q1[q1_fwd+1]=1;
				if(!flag) q1[q1_fwd+1]=0;  
				q1_fwd++;
			} 
		}
		if(is==false) cout<<q1[q1_fwd]<<endl;
		else cout<<!q1[q1_fwd]<<endl;
	}
	Close();
	return 0;
} 
