#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int n;
	cin >> n;
	vector<int> s(2 * n);
	for (int i = 0; i < 2 * n; i++)
		cin >> s[i];
	
	sort(s.begin(), s.end());
	int min = s[0] + s[2 * n - 1];
	for (int i = 1, j = 2 * n - 2; i < n; i++, j--) {
		if (s[i] + s[j] < min)
			min = s[i] + s[j];
	}
	cout << min;
	return 0;
}
