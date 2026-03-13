class Solution {
public:
    typedef long long ll;

    bool can(ll T, int h, vector<int>& a) {
        ll total = 0;

        for (ll w : a) {
            ll x = (sqrt(1 + 8.0*T/w) - 1) / 2;
            total += x;

            if (total >= h) return true;
        }

        return false;
    }

    long long minNumberOfSeconds(int h, vector<int>& a) {
        ll l = 1, r = 1e18, ans = r;

        while (l <= r) {
            ll mid = (l + r) / 2;

            if (can(mid, h, a)) {
                ans = mid;
                r = mid - 1;
            } 
            else l = mid + 1;
        }

        return ans;
    }
};