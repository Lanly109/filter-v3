#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, ans[35];
int main(){
	freopen("power.in","r",stdin);
	freopen("power.out","w",stdout);
	cin >> n;
	if(n % 2 == 1) {
		cout << -1 << endl;
		return 0;
	}
	for(int i = 30; i >= 1; --i){
		if(n >= (1<<i)){
			n -= (1<<i);
			ans[i] = 1;
		}
	}
	for(int i = 30; i >= 1; --i){
		if(ans[i] == 1){
			cout << (1<<i) << ' ';
		}
	}
	cout << '\n';
}
