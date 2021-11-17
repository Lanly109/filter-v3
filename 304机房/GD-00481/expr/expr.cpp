#include <bits/stdc++.h>
#include <string.h>
#include <vector>

using namespace std;

string s;
int n,q;
int a[100010];
vector<int> c;

int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	cin>>s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);
	scanf("%d",&q);
	while(q--){
		int x;
		scanf("%d",&x);
		a[x]^=1;
		for(int i=0;i<s.size() ;i++){
			if(s[i]=='x') {
				i++;
				int sas=0;
				while(s[i]>='0'&&s[i]<='9'){
					sas*=10;
					sas+=s[i]-'0';
					i++;
				}
				i--;
				c.push_back(a[sas]);
			}else if(s[i]=='!'){
				int sas=c.front();
				c.pop_back();
				sas^=1;
				c.push_back(sas); 
			}else{
				int k=c.front();
				c.pop_back();
				int y=c.front();
				c.pop_back();
				if(s[i]=='&') if(k&&y) c.push_back(1);
				              else c.push_back(0);
				else if(k||y) c.push_back(1);
				     else c.push_back(0);   
			} 
		}
		printf("%d\n",c.front());
		c.pop_back() ;
	}
	return 0;
} 
