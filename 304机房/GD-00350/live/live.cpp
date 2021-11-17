#include <bits/stdc++.h>
using namespace std;
#define N 100010
#define ll long long
const int inf = 2e9;

template <class T>
inline void read(T& a){
	T x = 0, s = 1;
	char c = getchar();
	while(!isdigit(c)){ if(c == '-') s = -1; c = getchar();  }
	while(isdigit(c)){ x = x * 10 + (c ^ '0'); c = getchar();  }
	a = x * s;
	return ;
}

int a[N];   // ²åÖµÊı×é 
int n, k; 

int main(){ 
	freopen("live.in", "r", stdin); 
	freopen("live.out", "w", stdout); 
	read(n); read(k); 
	for(int i = 1; i <= n; i++){
		int x; read(x);
		a[x]++;
		int lim = max((i * k) / 100, 1);
		int sum = 0, id = 0; 
		for(int j = 600; j >= 0; j--){
			sum += a[j];
			if(sum == lim){
				id = j;
				break; 
			}
			if(sum > lim){
				id = j;
				break;
			}
		}
		printf("%d ", id); 
	}
	return 0;
}

