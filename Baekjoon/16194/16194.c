#include <stdio.h>
#include <malloc.h>

int main(void) {

    int n;
    scanf("%d", &n); //구매하려고 하는 카드의 개수 n

    int* p;

    p = (int*)malloc((n + 1) * sizeof(int)); 
    //카드팩별로 가격을 저장함. 배열의 원소는 카드팩에 들어있는 카드의 개수

    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]); //각 카드팩 별 가격
    }

    int* d;
    d = (int*)malloc((n + 1) * sizeof(int)); //각 카드의 최대값

    //배열 초기화
    d[0] = 0;
    for (int i = 1; i <= n; i++)
        d[i] = -1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) { //마지막에 구매한 카드팩 속 카드의 개수
            if (d[i] == -1 || d[i] > d[i - j] + p[j]){
                d[i] = d[i - j] + p[j];
            }
        }
    }

    printf("%d", d[n]);

    free(d);
    free(p);
	return 0;
}
