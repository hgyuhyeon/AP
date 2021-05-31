#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define CRT_SECURE_NO_WARNINGS

using namespace std;

bool dvisited[1001] = { false }, bvisited[1001] = { false }, l[10001][10001] = { false };
int v = 0;
queue<int> q;

void dfs(int node) {
	if (!dvisited[node]) {
		dvisited[node] = true;
		cout << node << " ";
		for (int i = 1; i <= v; i++) {
			if (l[node][i]) {
				dfs(i);
			}
		}
	}
}

void bfs(int node) {
	q.push(node);
	bvisited[node] = true;
	while (!q.empty()) {
		cout << q.front() << " ";
		for (int i = 1; i <= v; i++) {
			if (!bvisited[i] && l[q.front()][i]) {
				bvisited[i] = true;
				q.push(i);
			}
		}
		q.pop();
	}
}

int main(void) {

	cin.tie(NULL);
	cout.tie(NULL);

	int lines, n;

	cin >> v >> lines >> n;

	int num1, num2;
	for (int i = 0; i < lines; i ++) {
		cin >> num1 >> num2;
		l[num1][num2] = true;
		l[num2][num1] = true;
	}

	dfs(n);
	cout << "\n";
	bfs(n);

	return 0;
}
