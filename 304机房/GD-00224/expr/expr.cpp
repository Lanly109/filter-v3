#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char s[1000010];
int n,q,top=0,m;
int x[100010],b[100010];
int stack[100010];
int work(){
	top=0;
	for(int i=1;i<=m;i++){
		if(s[i]==' ') continue;
		if(s[i]=='x'){
			int t=0;
			++i;
			while(s[i]>='0'&&s[i]<='9'){
				t=t*10+(s[i]-'0');
				++i;
			}
			stack[++top]=x[t];
			continue;
		}
		if(s[i]=='!'){
			stack[top]=!stack[top];
			continue;
		}
		if(s[i]=='&'){
			stack[top-1]&=stack[top];
			--top;
			continue;
		}
		if(s[i]=='|'){
			stack[top-1]|=stack[top];
			--top;
		}
	}
	return stack[1];
}
int main()
{
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	gets(s+1);
	m=strlen(s+1);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=q;i++){
		x[b[i]]=!x[b[i]];
		printf("%d\n",work());
		x[b[i]]=!x[b[i]];
	}
	return 0;
}
