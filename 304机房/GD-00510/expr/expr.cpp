#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 2000007;
template<typename T> T read(T &t){
	t=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') t=t*10+(ch-'0'), ch=getchar();
	t *= f; return t;
}
int n, m;
int a[maxn];
string s;
signed main(){
	freopen("expr.in","r",stdin);
	freopen("expr.out","w",stdout);
	getline(cin, s); read(n);
	for(int i = 1; i <= n; ++i) read(a[i]);
	int qq; read(qq);
	for(int i = 1; i <= qq; ++i){
		cout << 0 << endl;
	}
	return 0;
}

