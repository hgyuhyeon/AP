int pairs(int k, vector<int> arr) {
    int ans = 0;
    map<int, int> m;
    for(auto i: arr) m[i]++;
    for(auto i: arr) if (m[i+k]) ans++;
    return ans;
}