#include <bits/stdc++.h>

using namespace std;

int main() {
    int size;
    cin >> size;

    vector<vector<int>> tri(size, vector<int>(1, 1));
    for (int lv = 2; lv <= size; lv++) {
        tri[lv-1].push_back(tri[lv-1][lv-1] + tri[lv-1][lv-2]);
    }

    for (auto i: tri) {
        for (auto j: i) {
            cout << j << " ";
        }
        cout << endl;
    }
    
    return 0;
}