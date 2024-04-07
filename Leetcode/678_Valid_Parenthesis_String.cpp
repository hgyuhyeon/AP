class Solution {
public:
    bool checkValidString(string s) {
        int cnt = 0, cntm = 0;
        for (auto c: s) {
            if (c == '(') {
                cnt++; cntm++;
            }
            else if (c == '*') {
                cnt++; cntm--; // * == ( , * == )
            }
            else {
                cnt--; cntm--;
            }
            
            if (cnt < 0) return false;
            else if (cntm < 0) cntm = 0; // * == ''
        }
        return cntm == 0 ? true : false;
    }
};