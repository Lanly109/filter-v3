#include<bits/stdc++.h>
using namespace std;
char c[1000001],lj[1000001];
int n,q,len=0;
int w[100001];
struct stk{
	bool b;
	bool x;
	char y;
};
stk s[100001];
stack<char> sc;
int main(){
	fstream fin("expr.in");
	ofstream fout("expr.out");
	int i,j=0;
	fin.getline(c,1000001);
	fin>>n;
	for(i=0;i<strlen(c);i++){
		if(c[i]=='!' || c[i]=='&' || c[i]=='|') lj[len++]=c[i];
		else if(c[i]=='x') lj[len++]=' ';
	}
	for(i=0;i<strlen(lj);i++){
		if(lj[i]==' '){
			s[i].b=true;
			fin>>s[i].x;
			w[j++]=i;
		}
		else{
			s[i].b=false;
			s[i].y=lj[i];
		}
	}
	fin>>q;
	int zb;
	for(i=1;i<=q;i++){
		fin>>zb;
		zb=w[zb];
		s[zb].x=!s[zb].x;
		for(j=0;j<strlen(lj);j++){
			if(!s[j].b) sc.push(s[j].y);
			else sc.push(s[j].x);
			if(sc.top()=='!'){
				sc.pop();
				bool x1=!sc.top();
				sc.pop();
				sc.push(x1);
			}
			if(sc.top()=='|'){
				sc.pop();
				bool x1=sc.top(),x2;
				sc.pop();
				x2=sc.top();
				sc.pop();
				sc.push(x1 || x2);
			}
			if(sc.top()=='&'){
				sc.pop();
				bool x1=sc.top(),x2;
				sc.pop();
				x2=sc.top();
				sc.pop();
				sc.push(x1 && x2);
			}
		}
		s[zb].x=!s[zb].x;
		fout<<sc.top()<<endl;
	}
	return 0;
}
