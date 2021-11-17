#include <stdio.h>
#include <string.h>

int main() {
	freopen("live.in", "r", stdin);
	freopen("live.out", "w", stdout);
	int n, w, i, j, read, mark;
	scanf("%d %d", &n, &w);
	int s[n], l[n];
	memset(s, 0, sizeof(s));
	for (i = 0; i < n; i++) {
		scanf("%d", &read);
		j = 0;
		while (s[j] > read)
			j++;
		mark = j;
		for (j = i; j > mark; j--)
			s[j] = s[j - 1];
		s[mark] = read;
		if (((i + 1) * w / 100) > 1)
			l[i] = s[(i + 1) * w / 100 - 1];
		else 
			l[i] = s[0];
	}
	printf("%d", l[0]);
	for (i = 1; i < n; i++) {
		printf(" ");
		printf("%d", l[i]);
	}
	printf("\n");
	return 0;
}
