#include <stdio.h>
#include <malloc.h>
int main(void) {

	int num, card; //card: number of cards, num: targetnumber
	scanf("%d %d", &card, &num);

	int* subnum; //to save which is written on the cards
	subnum = (int*)malloc(card * sizeof(int));
	for (int i = 0; i < card; i++) {
		scanf("%d", &subnum[i]);
	}

	//insert all of sum numbers
	int i, j, k, m, result = 0;
	for (i = 0; i < card - 2; i++) {
		for (j = i + 1; j < card - 1; j++) {
			for (k = j + 1; k < card; k++) {
				m = subnum[i] + subnum[j] + subnum[k];
				if (m <= num&&m > result) {
					result = m;
				}
			}
		}
	}
	//print
	printf("%d", result);

	return 0;
}

//https://www.acmicpc.net/problem/2798
