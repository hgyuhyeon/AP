#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {

	int n, m, p, temp = 0, answer = 0;
	string s;
	cin >> n >> m >> s;
	p = 1 + n * 2;

	for (int i = 0; i < m; i++) {
		if (s[i] == 'I') {
			if (temp % 2 == 0)
				temp++;
			else
				temp = 1;
		}
		else {
			if (temp % 2 == 1)
				temp++;
			else
				temp = 0;
		}
		//cout << "i: " << i << " temp: " << temp << endl;
		if (temp == p) {
			answer++;
			temp -= 2;
		}
		//cout << "i: " << i << " temp: " << temp << endl;
	}

	cout << answer;
 
	return 0;
}
