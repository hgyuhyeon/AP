#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

void dijkstra(vector<vector<pair<int, int>>> &g, vector<int> &d, int start) {
	d[start] = 0;

	priority_queue<pair<int, int>> pq;
	pq.push({ d[start], start }); //비용, 위치

	while (!pq.empty()) {
		int c = pq.top().second; 
		int dist = pq.top().first * -1;
		pq.pop();

		if (d[c] < dist) continue;

		for (int i = 0; i < g[c].size(); i++) { //버스 노선중에
			//cout << c << g[c].size() << endl;
			int nc = g[c][i].first; 
			int ndist = dist + g[c][i].second;

			if (ndist < d[nc]) {
				d[nc] = ndist; 
				pq.push({ d[nc] * -1, nc }); 
			}
		}
	}
}

int main(void) {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<pair<int, int>>> g(n+1); //버스 노선
	vector<int> d(n+1); //비용
	for (int i = 1; i < d.size(); i++)
		d[i] = 987654321; 

	int u, v, w;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		g[u].push_back({ v,w }); //시작노선에 목적지랑 비용 넣음
	}

	int start, end;
	cin >> start >> end;


	dijkstra(g, d, start);

	cout << d[end];

	return 0;
}
