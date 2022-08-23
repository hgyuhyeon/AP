#include <stdio.h>

int main(void) {

	int n, m = 0;
	float score[1000], sum = 0, avg;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%f", &score[i]);
		if (score[i] > m)
			m = score[i];
	}

	for (int i = 0; i < n; i++) {
		score[i] = score[i] / (float)m * 100;
		sum += score[i];
	}

	avg = sum / (float)n;
	printf("%f", avg);

	return 0;
}
