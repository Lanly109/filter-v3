#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("expr.in", "r", stdin);
	freopen("expr.out", "w", stdout);
	string s;
	int ans = 0;
	for(;true;){
		cin >> s;
		if(s == "&"){
			ans = 0;
			break; 
		}
		else if(s == "|"){
			ans = 1;
			break;
		}
	}
	for(int i = 0; i < 3; ++i) cout << ans << endl;
	return 0;
}
