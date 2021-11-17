#include<bits/stdc++.h>
using namespace std;
stack<int> a;
string s;
int n,d,q,tmp,t1,t2;
int num[100007],mem[100007];
int main(){//30pts
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	getline(cin,s);
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&num[i]);
	}
	scanf("%d",&q);
	for(int j=1;j<=q;++j){
		scanf("%d",&d);
		if(mem[d]){
			printf("%d\n",mem[d]);
			continue;
		}
		num[d]=1-num[d];
		for(int i=1;i<s.length();++i){
			if(s[i]>='0'&&s[i]<='9'){
				tmp*=10;
				tmp+=s[i]-'0';
			}
			else if(tmp!=0){
				a.push(num[tmp]);
				tmp=0;
			}
			else{
					if(s[i]=='&'){
						t1=a.top();
						a.pop();
						t2=a.top();
						a.pop();
						a.push(t1&&t2);
					}
					if(s[i]=='|'){
						t1=a.top();
						a.pop();
						t2=a.top();
						a.pop();
						a.push(t1||t2);
					}
					if(s[i]=='!'){						
						t1=a.top();
						a.pop();
						a.push(1-t1);
					}
				}		
			}
			mem[d]=a.top();
			printf("%d\n",a.top());
			a.pop();
			num[d]=1-num[d];
	}	
	return 0;
} 
