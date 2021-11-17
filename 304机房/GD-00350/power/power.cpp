#include <bits/stdc++.h>
using namespace std;
#define N 1000010
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

ll n;

ll qpow(ll b){
	ll sum = 1, a = 2;
	while(b){
		if(b & 1) sum = sum * a;
		a *= a;
		b >>= 1;  
	} 
	return sum; 
}

int main(){
	freopen("power.in", "r", stdin);
	freopen("power.out", "w", stdout); 
	cin >> n;
	if(n % 2 == 1){
		cout << -1;
		return 0; 
	}
	int id = 0; 
	for(int i = 1; i <= n; i++){
		if(qpow(i) > n){
			id = i;
			break; 
		} 
	}
	id--; 
	while(n > 0){ 
		ll tmp = qpow(id);
		n -= tmp;  
		printf("%lld ", tmp); 
		for(int i = 1; i <= n; i++)
			if(qpow(i) > n){
				id = i - 1; 
				break; 
			}
	}
	return 0;
}
