class Solution {
public:
    int solve(int n, int k) {
        if (k == 1)
            return 0;
        if (((k)&k) == 0)
            return 1;
        int t = 1 << n;
        if (k * 2 < t - 1) {
            return solve(n - 1, k);
        }
        return solve(n - 1, t - k) ^ 1;
    }

    char findKthBit(int n, int k) {
        return solve(n,k)+'0';
    }
};
