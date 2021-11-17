#include<cstdio>
#include<iostream>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;
int n;
stack<int>stk; 
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	scanf("%d",&n);
	if(n%2||n==0){
		printf("-1");
		return 0;
	}
	while(n){
		stk.push(n&1);
		//printf("%d",stk.top());
		n>>=1;
	}
	while(stk.size()){
		int a=stk.top()*(int)pow(2,stk.size()-1);
		if(a)
			printf("%d ",a);
		stk.pop();
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
