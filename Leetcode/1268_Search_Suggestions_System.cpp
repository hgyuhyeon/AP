class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> ans;
        sort(products.begin(), products.end());
        string w = "";
        for (auto c: searchWord) {
            vector<string> tmp;
            w += c;
            int loc = upper_bound(products.begin(), products.end(), w) - products.begin(), cnt = 0;
            
            if (loc > 0 && products[loc-1] == w) {
                tmp.push_back(w.substr(0, products[loc-1].size()));
                cnt++;
            }
            while (loc < products.size() && cnt++ < 3) {
                if (products[loc].size() >= w.size() && products[loc].substr(0, w.size()) == w) tmp.push_back(products[loc]);
                else break;
                loc++;
            }
            ans.push_back(tmp);                
        }
        return ans;
    }
};
