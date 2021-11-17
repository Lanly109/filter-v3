#include<iostream>
#include<cstring>
#include<string>
#include<stack>
#include<cstdio>
using namespace std;
int a[100001];					//变量下标 
char b[100001];					//操作 
bool c[100001];					//值 
stack<char> q;
string s;
int n,m;
bool findans(){
	bool ans=c[a[1]];
	for(int i=2; i<=n; i++){
		if(b[i] == '&'){
			ans = ans&&c[a[i]];
		}
		if(b[i] == '|'){
			ans = ans||c[a[i]];
		}
		if(b[i] == '!'){
			ans = !ans;
		}
	}
	return ans;
} 
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	getline(cin,s);
	int temp=0,k=0;
	for(int i=0; i<s.length(); i++){
		if(s[i]=='&' || s[i]=='|' || s[i]=='!'){
			a[++k] = q.top();
			b[k] = s[i];
			continue;
		}
		if(s[i] == 'x'){
			temp=0;
			continue;
		}
		if(s[i]>='0' && s[i]<='9'){
			temp = temp*10+(s[i]-'0');
			continue;
		}
		if(s[i] == ' ' && s[i-1]>='0' && s[i-1]<='9'){
			q.push(temp);
			temp=0;
		}
	}
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>c[i];
	}
	cin>>m;
	int x;
	for(int i=1; i<=m; i++){
		cin>>x;
		c[x] = !c[x];
		bool an;
		an=findans();
		if(an==true){
			cout<<1;
		}
		else{
			cout<<0;
		}
		c[x] = !c[x];
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

