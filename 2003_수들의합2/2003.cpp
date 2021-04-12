#include <iostream>
#include <vector>

using namespace std;
 
int main(void) {
	
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m, answer = 0;
	cin >> n >> m;
	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int begin = 0, sum = arr[0], i = 1;
	while (1) {
		if (i <= n-1) {
			sum += arr[i];
			i++;
			//cout << sum << " " << i << endl;
		}
		if (sum == m) {
			answer++;
			sum -= arr[begin];
			begin++;
			//cout << sum << " " << i << " " <<answer<<endl;
		}
		while (sum >= m) {
			if (sum == m) {
				answer++;
			}
			sum -= arr[begin];
			begin++;
			//cout << sum << " " << i << " while" << endl;
		}
		if (i == n)
			break;
	}
	cout << answer;
	return 0;
}
