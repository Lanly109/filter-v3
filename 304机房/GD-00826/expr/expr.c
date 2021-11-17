#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int main() {
	freopen("expr.in", "r", stdin);
	freopen("expr.out", "w", stdout);
	char c, num[1000];
	int count = 0, x[100000], i, j, p = 0, n, number1, number2,  xs[100000], xs2[100000];
	while((c = getchar()) != '\n') {
		if ((c >= '1') && (c <= '9'))
			num[count++] = c;
		else if (count != 0) {
			for (i = count; i > 0; i--) {
				n = num[count - i]; 
				for (j = 0; j < i; j++)
					n *= 10;
				x[p] += n;
				count = 0;
			}
			p++;
		}
		else if ((c == '&') || (c == '!') || (c == '|')) 
			x[p++] = c;
	}
	scanf("%d", &number1);
	for (i = 0; i < number1; i++)
		scanf("%d", &xs[i]); 
	scanf("%d", &number2);
	for (i = 0; i < number2; i++) {
		scanf("%d", &xs2[i]);
		xs[xs2[i]] = !xs[xs2[i]];
	}
	for (i = 0; i < p; i++) {
		if (isdigit(x[i]))
			x[i] = xs[x[i]];
		switch (x[i]) {
			case '!':
				if(x[i - 1] == 0)
					x[i - 1] = 1;
				else
					x[i - 1] = 0;
				for (j = i; j < p - 1; j++) 
					x[j] = x[j + 1];
				x[j] = 0;
			case '&':
				if (x[i - 1] == 1 && x[i - 2] == 1) {
					x[i - 2] = 1;
				}
				for (j = i - 1; j < p - 1; j++) 
					x[j] = x[j + 1];
				x[j] = 0;
			case '|':
				if (x[i - 1] == 1 || x[i - 2] == 1)
					x[i - 2] ==  
				for (j = i - 1; j < p - 1; j++) 
					x[j] = x[j + 1];
				x[j] = 0;
		}
	}
	printf("%d", x[0]);
	return 0;
}
