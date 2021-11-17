#include <bits/stdc++.h>

using namespace std;

char s[1000005];
bool x[100005];
bool a[100005];
int ai;
int n;
int q;

int main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	
	gets(s);
	cin >> n;
	
	for(int i = 1;i <= n;i++){
		cin >> x[i];
	}
	
	cin >> q;
	
	int qi;
	
	//printf("%d",q);
	
	while(q--){
		scanf("%d",&qi);
		x[qi] = !x[qi];
		
		ai = 0;
		for(int i = 0;i < strlen(s);i++){
			if(s[i] == ' ')continue;
			if(s[i] == 'x'){
				int e = 0;
				while(s[i + 1] <= '9' && s[i + 1] >= '0'){
					i++;
					e = e * 10 + s[i] - '0';
				}
				a[++ai] = x[e];
				continue;
			}
			
			if(s[i] == '!'){
				a[ai] = !a[ai];
				continue;
			}
			
			if(s[i] == '&'){
				a[ai - 1] = a[ai] && a[ai - 1];
				ai--;
				continue;
			}
			
			if(s[i] == '|'){
				a[ai - 1] = a[ai] || a[ai - 1];
				ai--;
				continue;
			}
		}
		printf("%d\n",a[ai]);
		x[qi] = !x[qi];
	}
		
	return 0;
} 
