#include <stdio.h>
#define SIZE 1000000

int main(void) {

	char s[SIZE];
	int space = 1, count = 0;

	scanf("%[^\n]s", &s);

	for (int i = 0; s[i]; i++) {
		if (s[i] == ' ') {
			space = 1;
		}
		else if (space) {
			space = 0;
			count++;
		}
	}

	printf("%d", count);

	return 0;
}
