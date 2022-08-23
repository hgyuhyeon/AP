#include <stdio.h>
#include <malloc.h>
#define _CRT_SECURE_NO_WARNINGS

int main(void) {

	int n;
	scanf("%d", &n);
	if ((n > 10000000)||(n<1))
		return 0;

	int num, max = 0;
	int count[10001] = { 0 };

	int k;
	for (k = 0; k < n; k++) {
		scanf("%d", &num);

		if (num > max)
			max = num;

		count[num] += 1;
	}

	int i, j;
	for (i = 1; i <= max; i++) {
		if (count[i] != 0) {
			for (j = 0; j < count[i]; j++) {
				printf("%d ", i);
			}
		}
	}

	return 0;
}
