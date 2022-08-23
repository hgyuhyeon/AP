#include <stdio.h>
#include <malloc.h>
void swap(int* a, int* b);
int main(void) {
	int num, * chart;
	scanf("%d", &num);
	chart = (int*)malloc(num * sizeof(int));
	for (int i = 0; i < num; i++) {
		scanf("%d", &chart[i]);
	}

	int minindex;
	for (int n = 0; n < num - 1; n++) {
		minindex = n;
		//find_min
		for (int m = n + 1; m < num; m++) {
			if (chart[m] < chart[minindex])
				minindex = m;
		}
		swap(&chart[n], &chart[minindex]);
	}

	for (int j = 0; j < num; j++) {
		printf("%d\n", chart[j]);
	}

	return 0;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
//https://www.acmicpc.net/problem/2750
