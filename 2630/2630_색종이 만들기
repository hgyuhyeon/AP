#include <iostream>
#include <vector>

using namespace std;

int v[128][128];
int blue = 0, white = 0;

int divide(int x, int y, int n) {
	if (n == 1) {
		if (v[x][y] == 1) blue++;
		else white++;
		return v[x][y];
	}

	int num = 0;
	num += divide(x, y, n / 2);
	num += divide(x + (n / 2), y, n / 2);
	num += divide(x, y + (n / 2), n / 2);
	num += divide(x + (n / 2), y + (n / 2), n / 2);
		
	if (num == 0) {
		white -= 3;
		return 0;
	} 
	else if (num == 4) {
		blue -= 3;
		return 1;
	}


	return -128;
}

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n;
	cin >> n;

	for(int i =0;i<n;i++)
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}

	divide(0, 0, n);

	cout << white << "\n" << blue;
	return 0;
}
