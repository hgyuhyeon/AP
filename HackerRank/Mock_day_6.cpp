vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<vector<int>> eg(n+1, vector<int>());
    vector<bool> v(n+1, false);
    vector<int> dist(n+1, INT_MAX), ans;
    dist[s] = 0; dist[0] = 0;
    
    for (auto e: edges) {
        eg[e[0]].push_back(e[1]);
        eg[e[1]].push_back(e[0]);
    }
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        if (!v[q.front()]) {
            v[q.front()] = true;
            for (auto e: eg[q.front()]) {
                dist[e] = min(dist[e], dist[q.front()]+6);
                q.push(e);
            }
        }
        q.pop();
    }
    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        if (dist[i] == INT_MAX) ans.push_back(-1);
        else ans.push_back(dist[i]);
    }
    return ans;
}