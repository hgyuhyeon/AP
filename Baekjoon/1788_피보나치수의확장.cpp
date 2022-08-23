#include <iostream>
#include <vector>

using namespace std;

int main(void) {

    int m;
    cin >> m;
    if (m == 0) {
        cout << "0\n0";
        return 0;
    }
    int absm = abs(m);
    vector<int> v(absm + 2);
    v[0] = 0;
    v[1] = 1;
    for (int i = 2; i <= absm; i++) {
        v[i] = (v[i - 1] + v[i - 2]) % 1000000000;
    }
    if (m < 0 && absm % 2 == 0)
        cout << -1 << "\n";
    else
        cout << 1 << "\n";

    cout << v[absm];
    return 0;
}
