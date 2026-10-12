class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<long long> base;
        long long x = 1;

        while (x <= 1000000000) {
            base.push_back(x);
            x <<= 1;
        }

        int nb = base.size();
        vector<int> count(nb, 0);

        for (int x : nums) {
            for (int i = 0; i < nb; i++) {
                if (x & base[i])
                    count[i]++;
            }
        }

        vector<long long> values(k, 0);

        for (int i = 0; i < nb; i++) {
            for (int j = 0; j < min(k, count[i]); j++) {
                values[j] += base[i];
            }
        }

        long long res = 0;
        const long long mod = 1000000007;

        for (long long y : values) {
            res = (res + y * y) % mod;
        }

        return res;
    }
};