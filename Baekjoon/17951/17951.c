#include <stdio.h>
#include <stdlib.h>

int main(void) {
	
	int num, group, subgroup, min;
	int* score, * chart;

	scanf("%d %d", &num, &group);
	score = (int*)malloc(num * sizeof(int)); //점수 저장
	chart = (int*)calloc(group, sizeof(int)); // 나눠진 그룹별(예:그룹1, 그룹2)로 점수의 합 저장

	for (int i = 0; i < num; i++)
		scanf("%d", &score[i]);

	subgroup = num / group; //그룹당 원소 수(예: 8 / 2 = 4)

	int j = 0;
	for (int i = 0; i < group; i++) {
		for (j = i * subgroup; j < i * subgroup + subgroup; j++) {
			if (j >= num)
				break;
			chart[i] += score[j];
		}
	} //그룹별 점수의 합 저장중

	min = chart[0];
	for (int k = 1; k < group; k++) {
		if (chart[k] < chart[k - 1])
			min = chart[k];
	} //그룹별 점수의 합 중 최소값 찾는중

	printf("%d", min);

	free(score);
	free(chart);
	return 0;
}

//https://www.acmicpc.net/problem/17951
