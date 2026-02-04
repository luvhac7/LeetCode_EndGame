class Solution {
public:
    using ll = long long;

    ll maxSumTrionic(vector<int>& a) {
        a.push_back(INT_MIN);
        int n = a.size();

        vector<ll> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + a[i];

        ll ans = LLONG_MIN;
        int pre = -1, cur = -1;
        bool inc = false;

        for (int i = 0; i < n - 1; i++) {
            int x = a[i], y = a[i + 1];

            if (x < y) { // increasing
                if (!inc) {
                    inc = true;
                    cur = i;
                }
                if (pre != -1)
                    ans = max(ans, pref[i + 2] - pref[pre]);
            } else if (y < x) { // decreasing
                if (inc)
                    pre = cur;
                inc = false;
            } else { // equal
                pre = cur = -1;
                inc = false;
            }

            while (pre != -1 && pre + 2 < n && a[pre + 1] < a[pre + 2] &&
                   a[pre] < 0) {
                pre++;
            }
        }
        return ans;
    }
};
