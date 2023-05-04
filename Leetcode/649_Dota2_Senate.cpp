class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<char> q;
        for (auto s: senate) q.push(s);

        int rban = 0, dban = 0, same = 0;
        char prev = 'A';

        do {
            char val = q.front();
            if (val == prev) same++;
            else {
                prev = val;
                same = 0;
            }
            q.pop();
            switch(val) {
                case 'R':
                    if (!rban) {
                        q.push(val);
                        dban++;
                    }
                    else rban--;
                    break;
                case 'D':
                    if (!dban) {
                        q.push(val);
                        rban++;
                    }
                    else dban--;
                    break;
                default: break;
            }
        } while (q.size() > 1 && same < q.size());

        if (q.front() == 'R') return "Radiant";
        else return "Dire";
    }
};