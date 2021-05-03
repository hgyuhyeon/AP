#include <iostream>
#include <queue>

using namespace std;

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	priority_queue<int> pq;

	int n, m;
	cin >> n >> m;
	int vote = m;
	for (int i = 1; i < n; i++) {
		cin >> m;
		pq.push(m);
	}

	int min = 0;
	while (!pq.empty() && pq.top() >= vote) {
		m = pq.top();
		pq.pop();
		vote++;
		pq.push(m - 1);
		min++;
	}

	cout << min;

	return 0;
}
