#include <iostream>
#include <set>

using namespace std;

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	set<string> s;

	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		s.insert(temp);
	}

	set<string> res;
	int count = 0;
	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (s.find(temp)!=s.end()) {
			res.insert(temp);
			count++;
		}
	}

	cout << count << "\n";
	for (auto i: res) {
		cout << i << "\n";
	}

	return 0;
}
