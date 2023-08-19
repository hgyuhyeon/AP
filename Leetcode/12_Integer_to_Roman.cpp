class Solution {
public:
    string intToRoman(int num) {
        map<int, string> m;
        m[1] = "I";
        m[4] = "IV";
        m[5] = "V";
        m[9] = "IX";
        m[10] = "X";
        m[40] = "XL";
        m[50] = "L";
        m[90] = "XC";
        m[100] = "C";
        m[400] = "CD";
        m[500] = "D";
        m[900] = "CM";
        m[1000] = "M";

        string ans = "";
        int mul = 1000;
        while (num > 0) {
            int val = num / mul;
            
            if (val == 4 || val == 9) {
                ans += m[val * mul];
            }
            else if (val >= 5) {
                ans += m[5 * mul];
                for (int i = 0; i < val - 5; i++) ans += m[mul];
            }
            else {
                for (int i = 0; i < val; i++) ans += m[mul];
            }

            num %= mul;
            mul /= 10;
        }

        return ans;
    }
};