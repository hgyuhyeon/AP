class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        map<int, string> m;
        m[1] = "One";
        m[2] = "Two";
        m[3] = "Three";
        m[4] = "Four";
        m[5] = "Five";
        m[6] = "Six";
        m[7] = "Seven";
        m[8] = "Eight";
        m[9] = "Nine";
        m[10] = "Ten";
        m[11] = "Eleven";
        m[12] = "Twelve";
        m[13] = "Thirteen";
        m[14] = "Fourteen";
        m[15] = "Fifteen";
        m[16] = "Sixteen";
        m[17] = "Seventeen";
        m[18] = "Eighteen";
        m[19] = "Nineteen";
        m[20] = "Twenty";
        m[30] = "Thirty";
        m[40] = "Forty";
        m[50] = "Fifty";
        m[60] = "Sixty";
        m[70] = "Seventy";
        m[80] = "Eighty";
        m[90] = "Ninety";
        m[100] = "Hundred";
        m[1000] = "Thousand";
        m[1000000] = "Million";
        m[1000000000] = "Billion";
        long mul = 1;
        string ans = "";
        while (num > 0) {
            int num2 = num % 1000;
            if (num2) {
                if (mul >= 1000) ans = " " + m[mul] + ans;
                if (num2 % 100 < 20 && num2 % 100 > 0) {
                    ans = " " + m[num2 % 100] + ans;
                }
                else {
                    if (num2 % 10 > 0) ans = " " + m[num2 % 10] + ans;
                    if (num2 % 100 - num2 % 10 > 0) ans = " " + m[num2 % 100 - num2 % 10] + ans;
                }
                if (num2 % 1000 - num2 % 100 > 0) ans = " " + m[num2 / 100] + " " + m[100] + ans;
            }
            num /= 1000;
            mul *= 1000;
        }
        return ans.substr(1);
    }
};
