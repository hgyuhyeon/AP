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
        int n, k;
        cin >> n >> k;
       	vector<vector<int>> v(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> v[i][j];
        }
		
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            int cnt = 0, cnt2 = 0;
            for (int j = 0; j < n; j++) {
                if (v[i][j]) cnt++;
                else {
                    m[cnt]++; 
                    cnt = 0;
                }

                if (v[j][i]) cnt2++;
                else {
                    m[cnt2]++; 
                    cnt2 = 0;
                }
            }
            m[cnt]++;
            m[cnt2]++;
        }

        cout << m[k] << endl;
	}
	return 0;
}