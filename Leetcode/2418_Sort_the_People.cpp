class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();
        for (int i = 0; i < n; i++) {
            int max_i = max_element(heights.begin()+i, heights.end()) - heights.begin();
            swap(names[i], names[max_i]);
            swap(heights[i], heights[max_i]);
        }
        return names;
    }
};
