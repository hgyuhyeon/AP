#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, string> u, pair<int, string>v) {
	return u.first < v.first;
}

int main(void) {

	int n;
	cin >> n;
	pair<int, string> p;
	vector<pair<int, string>> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first >> v[i].second;
	}

	stable_sort(v.begin(), v.end(), cmp);

	for (auto i: v)
		cout << i.first << " " << i.second << "\n";

	return 0;
}
