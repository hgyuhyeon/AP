class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        multiset<char> s;
        for (auto i: magazine) {
            s.insert(i);
        }
        
        for (auto i: ransomNote) {
            if (s.find(i) == s.end())
                return false;
            else
                s.erase(s.find(i));
        }
        return true;
    }
};