class Solution {
public:
    int p[26];

    int Find(int x) {
        if (p[x] == -1) return x;
        else return Find(p[x]);
    }

    void Union(int x, int y) {
        x = Find(x);
        y = Find(y);

        // if x and y don't have same parent
        if (x != y) p[max(x, y)] = min(x, y);
        // put min element into max element's parent
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        memset(p, -1, sizeof(p));

        for (auto i = 0; i < s1.size(); i++) 
            Union(s1[i] - 'a', s2[i] - 'a');
        
        for(auto i=0; i < baseStr.size(); i++) 
            baseStr[i] = Find(baseStr[i] - 'a') + 'a';

        return baseStr;
    }
};