#include<cstdio>
#include<stack>
#include<string>
#include<iostream>
using namespace std;
string e;
int n,q,x[100005];
int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	getline(cin,e);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int t;
		scanf("%d",&t);
		stack<int> st;
		for(int j = 0;j < e.size();j++){
			if(e[j] == 'x'){
				int num=0,k=j+1;
				while(e[k] >= '0' && e[k] <= '9'){
					num = num * 10 + (e[k] - 48);
					k++;
				}
				if(num == t) st.push(!x[num]);
				else st.push(x[num]);
			}else if(e[j] == '&'){
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				st.push(a&b);
			}else if(e[j] == '|'){
				int a = st.top();
				st.pop();
				int b = st.top();
				st.pop();
				st.push(a|b);
			}else if(e[j] == '!'){
				int a = st.top();
				st.pop();
				st.push(!a);
			}
		}
		printf("%d\n",st.top());
	}
	return 0;
}
