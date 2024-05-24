#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int num, n;
	map<int, int> m;
	cin >> num >> n;
	for (int i = 0, val; i < n; i++) {
		cin >> val;
		m[val]++;
	}

	int ans = abs(100 - num);
	for (int i = 0; i <= 1000000; i++) {
		string tmp = to_string(i);
		bool flag = true;
		for (auto c : tmp) {
			if (m[c-'0'] > 0) {
				flag = false;
				break;
			}
		}
		if (flag) ans = min(ans, abs(num - i) + (int)to_string(i).size());
	}
	cout << ans;
	return 0;
}