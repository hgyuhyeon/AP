#include <iostream>
#include <queue>

using namespace std;

struct cmp {
	bool operator() (int a, int b) {
		if (abs(a) == abs(b))
			return (a > b);
		else
			return (abs(a) > abs(b));
	}
};

int main(void) {

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	priority_queue<int, vector<int>, cmp> pq;

	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (m == 0) {
			if (pq.empty())
				cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else {
			pq.push(m);
		}
	}

	return 0;
}
