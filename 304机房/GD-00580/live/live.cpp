#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100021;
int N, W;
int p;
int a[maxn];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	freopen("live.in", "r", stdin);
	freopen("live.out", "w", stdout);
	scanf("%d%d", &N, &W);
	for(int i = 0; i < N; i++){
		int s = max(1, (i + 1) * W / 100);
		scanf("%d", a + i);
		sort(a, a + i + 1, cmp);
		printf("%d ", a[s - 1]);
	}
	return 0;
} 
