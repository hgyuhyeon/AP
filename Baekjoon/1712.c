#include <stdio.h>

int main(void) {

	int staticpay, dynamicpay, price, count;
	scanf("%d %d %d", &staticpay, &dynamicpay, &price);

	if (price - dynamicpay > 0) {
		count = staticpay / (price - dynamicpay) + 1;
	}
	else {
		count = -1;
	}

	printf("%d", count);

	return 0;
}
