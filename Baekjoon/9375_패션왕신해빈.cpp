#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m, answer;
	string cloth = "", category="";

	map<string, int> clothes;

	cin >> n;
	for (int i = 0; i < n; i++) {
		answer = 1;
		clothes.clear();
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> cloth >> category;
			clothes[category]++;
		}
		for (auto iter = clothes.begin(); iter != clothes.end(); iter++) {
			answer *= (iter->second + 1);
		}
		cout << answer - 1 << "\n";
	}
	return 0;
}
