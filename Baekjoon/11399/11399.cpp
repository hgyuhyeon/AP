#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int n;
	cin >> n;
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		cin >> p[i];

	sort(p.begin(), p.end());

	int sum = 0, answer = 0;
	for (auto i : p) {
		sum += i;
		answer += sum;
	}
	cout << answer;

	return 0;
}
