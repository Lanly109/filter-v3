#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
int n,q,opn;
string s;
int op[1000010];
bool num[100010];
int qs[100010];
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	memset(op,0,sizeof(op));
	memset(num,0,sizeof(num));
	memset(qs,0,sizeof(qs));
	for(int t=0;true;t++){
		cin>>s;
		if(s[0]!='x'&&s[0]!='&'&&s[0]!='|'&&s[0]!='!'){
			n=0;
			for(int i=0;i<s.size();i++){
			    n*=10;
			    n+=s[i]-'0';
			}
			opn=t;
			break;
		}
		if(s[0]=='x'){
			int p=0;
			for(int i=1;i<s.size();i++){
			    p*=10;
			    p+=s[i]-'0';
			}
			op[t]=p;
		}
		if(s[0]=='|')op[t]=-1;
		if(s[0]=='&')op[t]=-2;
		if(s[0]=='!')op[t]=-3;
	}
	for(int i=0;i<n;i++){
		cin>>num[i];
	}
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>qs[i];
	}
	for(int i=0;i<q;i++){
		num[qs[i-1]]=!num[qs[i-1]];
		stack<bool> number;
		for(int t=0;t<opn;t++){
			//cout<<op[t]<<" ";
			if(op[t]>=0)number.push(num[op[t]-1]);
			if(op[t]==-1){
				int tmp1=number.top();
				number.pop();
				int tmp2=number.top();
				number.pop();
				number.push(tmp1||tmp2);
			}
			if(op[t]==-2){
				int tmp1=number.top();
				number.pop();
				int tmp2=number.top();
				number.pop();
				number.push(tmp1&&tmp2);
			}
			if(op[t]==-3){
				int tmp=number.top();
				number.pop();
				number.push(!tmp);
			}
		}
		cout<<number.top()<<endl;
		num[qs[i-1]]=!num[qs[i-1]];
	}
	return 0;
}
