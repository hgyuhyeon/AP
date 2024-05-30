class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        int mw = 0, mh = 0, mod = 1e9 + 7;
        hc.push_back(0); hc.push_back(h);
        vc.push_back(0); vc.push_back(w);
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        for (int i = 1; i < hc.size(); i++) mh = max(mh, (hc[i] - hc[i-1])%mod);
        for (int i = 1; i < vc.size(); i++) mw = max(mw, (vc[i] - vc[i-1])%mod);
        return (1LL * mw * mh) % mod;
    }
};