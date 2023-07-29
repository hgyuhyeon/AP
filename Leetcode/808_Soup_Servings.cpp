class Solution {
public:
    double serve(int a, int b, unordered_map<int, unordered_map<int, double>>& m) {
        if (a <= 0 && b <= 0) return 0.5;
        if (a <= 0) return 1.0;
        if (b <= 0) return 0.0;
        if(m[a][b] != 0) return m[a][b];
        else m[a][b] = 0.25 * (serve(a-4, b, m) + serve(a-3, b-1, m) + serve(a-2, b-2, m) + serve(a-1, b-3, m));
        return m[a][b];
    }
    double soupServings(int n) {
        if (n > 4800) return 1.0;
        n = (n + 24) / 25;
        unordered_map<int, unordered_map<int, double>> m;
        
        return serve(n, n, m);
    }
};