#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {

	int n, weight;
	cin >> n;

	vector<int> r(n);
	for (int i = 0; i < n; i++)
		cin >> r[i];

	sort(r.begin(), r.end());

	weight = r[0] * n;
	cout << weight << endl;

	for (int i = 1; i < n; i++) {
		if (r[i] * (n - i) > weight)
			weight = r[i] * (n - i);
	}

	cout << weight;

	return 0;
}
