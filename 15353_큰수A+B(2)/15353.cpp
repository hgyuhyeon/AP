#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	string a, b, answer = "";
	cin >> a >> b;

	int carry = 0, sum = 0, ai, bi;

	int i = a.size() - 1, j = b.size() - 1;
	while ((i >= 0) || (j >= 0)) {
		if (i < 0) ai = 0;
		else ai = a[i--] - '0';
		if (j < 0) bi = 0;
		else bi = b[j--] - '0';
		sum = ai + bi + carry;

		answer += to_string(sum % 10);
		carry = sum / 10;
	}
	if (carry)
		cout << 1;
	reverse(answer.begin(), answer.end());
	cout << answer;
	return 0;
}
