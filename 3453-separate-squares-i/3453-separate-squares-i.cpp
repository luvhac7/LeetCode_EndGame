class Solution {
public:
    typedef double d;
    d below(vector<vector<int>>& sq, d y) {
        d ta = 0;
        for (auto& s : sq) {
            d btm = s[1];
            d len = s[2];
            if (btm < y) {
                ta += min(y - btm, len) * len;
            }
        }
        return ta;
    }
    d area(vector<vector<int>>& sq) {
        d ta = 0.0;
        for (auto& s : sq) {
            ta += (d)s[2] * s[2];
        }
        return ta;
    }
    double separateSquares(vector<vector<int>>& sq) {
        // bt
        d h = -1e18, l = 1e18;
        for (auto& s : sq) {
            h = max(h, (d)s[1] + s[2]);
            l = min(l, (d)s[1]);
        }
        d ta=area(sq);
        for (int i = 0; i < 80; i++) {
            d mid = (l + h) / 2;
            if (below(sq, mid) * 2 < ta) {
                l=mid;
            } else {    
                h=mid;
            }
        }
        return l;
    }
};