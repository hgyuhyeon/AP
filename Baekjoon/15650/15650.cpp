#include <iostream>
#define MAX 9
using namespace std;

int n, m;
int arr[MAX] = { 0, };
bool include[MAX] = { false, };

void dfs(int cnt)
{
    if (cnt == m) {
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!include[i]) {
            if ((cnt != 0 && arr[cnt - 1] < i) || cnt == 0) {
                include[i] = true;
                arr[cnt] = i;
                dfs(cnt + 1);
                include[i] = false;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    dfs(0);
}
