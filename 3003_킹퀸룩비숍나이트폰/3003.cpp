#include <iostream>

using namespace std;
 
int main(void) {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int t, c[6] = { 1,1,2,2,2,8 };

	for (int i = 0; i < 6; i++) {
		cin >> t;
		cout << c[i] - t;
		if (i != 5)
			cout << " ";
	}

	return 0;
}
