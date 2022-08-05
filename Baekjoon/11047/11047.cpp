#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int n, k;
	
	cin >> n >> k;
	vector<int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	int answer = 0, m = n;
	while (m > 0) {
		m--;
		if (k < a[m])
			continue;
		answer += (k / a[m]);
		k -= (k / a[m]) * a[m];
	}

	cout << answer;

	return 0;
}
