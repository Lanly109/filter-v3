#include<bits/stdc++.h>
using namespace std;
int n,q,a[200005],op[1000005],m;
string s;
int work(){
	stack<int>o;
	int os=0,f=0;
	for(int i=m;i;i--){
		if(op[i]>0)os++,o.push(a[op[i]]);
		else os=0,o.push(op[i]);
		while(os==1&&!o.empty()){
			int x=o.top();
			o.pop();
			if(o.empty())return x;
			int c=o.top();
			if(c==-3){
				o.pop();
				if(o.empty())return !x;
				if(o.top()>0)os++;
				o.push(!x);
			}else{
				o.push(x);
				break;
			} 
		}
		while(os==2&&!o.empty()){
			int x=o.top();
			o.pop();
			if(o.empty())return x;
			int y=o.top();
			o.pop();
			int c=o.top();
			o.pop();
			if(o.empty())return c==-1?x&y:x|y;
			if(o.top()<0)os--;
			o.push(c==-1?x&y:x|y);
		}
	}
	return o.top();
}
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	getline(cin,s);
	for(int i=0;s[i];i++){
		if(s[i]=='x'){
			int sum=0;
			while(s[++i]>='0'&&s[i]<='9')sum=sum*10+s[i]-48;
			op[++m]=sum;
		}else if(s[i]=='&')op[++m]=-1;
		else if(s[i]=='|')op[++m]=-2;
		else if(s[i]=='!')op[++m]=-3;
	}
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		a[x]^=1;
		printf("%d\n",work());
		a[x]^=1;
	}
	return 0;
}
