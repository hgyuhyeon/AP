#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
		cout <<"#" << test_case << " ";
        int n, k, mid, fin, hw;
        cin >> n >> k;
       	vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> mid >> fin >> hw;
            v[i] = mid * 35 + fin * 45 + hw * 20;
        }
		int ans = 0;
        vector<string> score = {"A+", "A0", "A-", "B+", "B0", "B-", "C+", "C0", "C-", "D0"};
        for (int i = 0; i < n; i++) if (v[i] > v[k-1]) ans++;
        cout << score[ans/(n/10)] << endl;

	}
	return 0;
}