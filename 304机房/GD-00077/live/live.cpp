#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("live.in", "r", stdin);
	freopen("live.out", "w", stdout);
	int n, w, score, num, list[601];
	cin >> n >> w;
	for(int i = 0; i < 601; ++ i) list[i] = 0;
	for(int i = 1; i < n + 1; ++ i){
		num = i * w / 100;
		if(num < 1) num = 1;
		cin >> score;
		list[score] += 1;
		int j = 601;
		while(num > 0){
			--j;
			num -= list[j];
		}
		cout << j << " ";
	}
	return 0;
}
