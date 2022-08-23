#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(void) {

    int n, diff = 2e9;
    cin >> n;

    vector<int> v(n);
    vector<int> res(2);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    int i = 0, j = v.size() - 1;

    while (i < j) {
        if (abs(v[i] + v[j]) <= diff) {
            diff = abs(v[i] + v[j]);
            res[0] = v[i];
            res[1] = v[j];
        }
        if (v[i] + v[j] < 0)
            i++;
        else if (v[i] + v[j] > 0)
            j--;
        else
            break;
    }

    cout << res[0] << " " << res[1];
    return 0;
}
