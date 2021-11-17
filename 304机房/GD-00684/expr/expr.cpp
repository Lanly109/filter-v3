#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
using namespace std;
char s[1000005];
int n,num[100005],q,change;
int cal(int num[],char s[])
{
	int ind=0,is=0;
	stack<int> st;
	for(int i=0;i<strlen(s);i++){
		if(s[i]=='x'){
			is=1;
			continue;
		}
		else if(s[i]>='0'&&s[i]<='9') ind=ind*10+(s[i]-'0');
		else if(s[i]==' '){
			if(is==1){
				st.push(num[ind]);
				ind=0;is=0;
			}
		}
		else if(s[i]=='&'||s[i]=='|'){
			int a=st.top();
			st.pop();
			int b=st.top();
			st.pop();
			if(s[i]=='&') st.push(a&b);
			else st.push(a|b);
		}
		else if(s[i]=='!'){
			int a=st.top()^1;
			st.pop();
			st.push(a);
		}
	}
	return st.top();
}

int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	gets(s);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&num[i]);
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d",&change);
		num[change]^=1;
		printf("%d\n",cal(num,s));
		num[change]^=1;
	}
	fclose(stdin);fclose(stdout);
	
	return 0;
} 
