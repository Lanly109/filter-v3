#include <stdio.h>

int max(int n, int * t, int p);

int main() {
	freopen("power.in", "r", stdin);
	freopen("power.out", "w", stdout);
	int n, i, j;
	scanf("%d", &n);
	if (n % 2 != 0) {
		printf("-1");
		return 0;
	}
	int t[30];
	for (i = 0; i < 30; i++) {
		t[i] = 2;
		for (j = 0; j < i; j++)
			t[i] = 2 * t[i];
	}
	int num = max(n, t, 30);
	printf("%d", num);
	n = n - num;
	while (n > 0) {
		printf(" ");
		num = max(n, t, 30);
		printf("%d", num);
		n = n - num;
	}
	printf("\n");
	return 0;
} 

int max(int n, int * t, int p) {
	int i;
	for (i = 0; i < p; i++)
		if(t[i] > n)
			return t[i - 1];
}
