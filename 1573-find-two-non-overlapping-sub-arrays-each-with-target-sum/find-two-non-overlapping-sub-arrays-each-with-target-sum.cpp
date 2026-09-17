class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int INF = n + 1;

        vector<int> minLen(n, INF);

        int left = 0;
        long long sum = 0;
        int best = INF;
        int ans = INF;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int len = right - left + 1;

                if (left > 0 && minLen[left - 1] != INF) {
                    ans = min(ans, len + minLen[left - 1]);
                }

                best = min(best, len);
            }

            minLen[right] = best;
        }

        return ans == INF ? -1 : ans;
    }
};