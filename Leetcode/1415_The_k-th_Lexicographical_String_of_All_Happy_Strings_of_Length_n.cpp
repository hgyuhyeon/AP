class Solution {
public:
    int n;
    vector<string> ans;
    char letter[3] = {'a', 'b', 'c'};
    
    void search(string& s) {
        if (s.size() == n) {
            ans.push_back(s);
            return;
        }
        for (int i = 0; i < 3; i++) {
            if (s.back() != letter[i]) {
                s.push_back(letter[i]);
                search(s);
                s.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        this->n = n;
        for (int i = 0; i < 3; i++) {
            string s(1, letter[i]);
            search(s);
        }
        sort(ans.begin(), ans.end());
        return ans.size() >= k ? ans[k-1] : "";
    }
};
