#include <stdio.h>

int main(void) {

	int go, back, height, day;
	scanf("%d %d %d", &go, &back, &height);

	if (go > back && back >= 1 && height >= go) {
		day = (height - back) / (go - back);
		if ((height - back) % (go - back) != 0) {
			day += 1;
		}
		printf("%d", day);
	}

	return 0;
}
