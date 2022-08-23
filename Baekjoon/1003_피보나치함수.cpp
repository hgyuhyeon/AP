#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    int n, m;
    cin >> n;

    for (int j = 0; j < n; j++) {
        cin >> m;
        vector<pair<int, int>> v(m+1);
        v[0] = make_pair(1, 0);
        if(m != 0)
            v[1] = make_pair(0, 1);
        for (int i = 2; i <= m; i++) {
            v[i].first = v[i - 1].first + v[i - 2].first;
            v[i].second = v[i - 1].second + v[i - 2].second;
        }
        cout << v[m].first << " " << v[m].second << "\n";
    }
    return 0;
}
