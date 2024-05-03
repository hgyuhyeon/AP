class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        vector<int> mul(num1.size()+num2.size(), 0);
        for (int i = mul.size()-1, j = num2.size()-1; j >= 0; i--, j--) {
            int idx = i;
            for (int k = num1.size()-1; k >= 0; k--) {
                mul[idx] += ((num1[k] - '0') * (num2[j] - '0'));
                if (mul[idx] / 10 > 0) {
                    mul[idx-1] += (mul[idx]/10);
                    mul[idx] %= 10;
                }
                idx--;
            }
        }

        int i = 0;
        string ans = "";
        while (mul[i] == 0) i++;
        while (i < mul.size()) ans += to_string(mul[i++]);
        return ans;
    }
};