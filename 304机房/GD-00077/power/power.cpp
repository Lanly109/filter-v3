#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("power.in", "r", stdin);
	freopen("power.out", "w", stdout);
	int num, len = 0, x = 0;
	cin >> num;
	int renum = num;
	for(; renum > 0; ++len) renum >>= 1;
	if(num % 2 == 1){
		cout << -1 << endl;
		return 0;
	}
	else{
		while(num > 0){
			int ans = pow(2, len);
			--len;
			if(num >= ans){
				cout << ans << " ";
				num -= ans;
			}
		}
	}
	return 0;
}
