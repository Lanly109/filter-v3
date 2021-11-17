#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e5+7;
template<typename T> T read(T &t){
	t=0; int f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while('0'<=ch&&ch<='9') t=t*10+(ch-'0'), ch=getchar();
	t *= f; return t;
}

int n, w, a[maxn], b[605];

signed main(){
	freopen("live.in","r",stdin);
	freopen("live.out","w",stdout);
	read(n); read(w);
	for(int i = 1; i <= n; ++i){
		read(a[i]);	
	}
	for(int i = 1; i <= n; ++i){
		b[a[i]]++;
		int nowrk = max(1, i*w/100), tmp = 0;
		for(int j = 600; j >= 0; --j){
			tmp += b[j];
			if(tmp >= nowrk){
				cout << j << ' ';
				break;
			}
		}
	}
	return 0;
}

