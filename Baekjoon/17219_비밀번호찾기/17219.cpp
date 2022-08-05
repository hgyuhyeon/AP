#include <iostream>
#include <map>

using namespace std;

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	string url = "", pwd = "";
	map<string, string> ps;
	for (int i = 0; i < n; i++) {
		cin >> url >> pwd;
		ps.insert({ url, pwd });
	}


	for (int i = 0; i < m; i++) {
		cin >> url;
		if (ps.count(url) == 1)
			cout << ps[url] << "\n";
	}

	return 0;
}
