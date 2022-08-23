#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	map<int, string> pmon;
	map<string, int> rpmon;

	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		pmon[i + 1] = temp;
		rpmon[temp] = i + 1;
	}

	for (int i = 0; i < m; i++) {
		cin >> temp;
		if (temp[0] >= '0' && temp[0] <= '9') {
			cout << pmon[stoi(temp)]<<"\n";
		}
		else {
			cout << rpmon[temp] << "\n";
		}
	}
	return 0;
}
