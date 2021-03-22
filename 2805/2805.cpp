#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cout.tie(NULL);

	int n, m, t;
	cin >> n >> m;

	vector<int> tree(n);
	for (int i = 0; i < n; i++) {
		cin >> t;
		tree[i] = t;
	}

	sort(tree.begin(), tree.end());

	int start = 0, end = tree[tree.size()-1], mid = (start + end) / 2;
	long long get = 0;
	while (end - start >= 0) {
		mid = (start + end) / 2;
		get = 0;
		
		for (int i = 0; i < tree.size(); i++)
			if (tree[i] - mid > 0) //잘려나가는 게 있으면
				get += (long long)tree[i] - mid;
		if (get == m) {
			cout << mid;
			break;
		}
		else if (get < m)
			end = mid - 1;
		else
			start = mid + 1;
	}

	if (end - start < 0) {
		if (mid == 0) {
			cout << mid;
		}
		else {
			get = 0;
			for (int i = 0; i < tree.size(); i++)
				if (tree[i] - mid > 0)
					get += (long long)tree[i] - mid;
			if (get < m)
				cout << mid - 1;
			else
				cout << mid;
		}
	}

	return 0;
}
