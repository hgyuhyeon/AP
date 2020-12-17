#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int compare(const void* a, const void* b);

int main(void) {
	int num, * chart;
	scanf("%d", &num);
	chart = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++) {
		scanf("%d", &chart[i]);
	}

	qsort(chart, num, sizeof(int),compare);

	for (int j = 0; j < num; j++) {
		printf("%d\n", chart[j]);
	}

	return 0;
}

int compare(const void* a, const void* b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2)
		return -1;
	if (num1 > num2)
		return 1;

	return 0;
}
//https://www.acmicpc.net/problem/2751
//About qsort(): https://dojang.io/mod/page/view.php?id=638
