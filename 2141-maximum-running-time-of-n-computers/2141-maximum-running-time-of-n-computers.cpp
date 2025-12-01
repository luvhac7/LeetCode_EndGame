class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int m = batteries.size();
        long long sum = 0;
        for (auto b : batteries)
            sum += b;

        auto ok = [&](long long t) -> bool {
            long long sum_mini = 0;
            int rem = n;
            for (auto b : batteries) {
                if (b >= t)
                    rem -= 1;
                else {
                    sum_mini += b;
                }
            }
            return sum_mini >= t * rem;
        };

        long long low = 0;
        long long hig = sum / n;
        while (low < hig) {
            long long mid = (low + hig + 1) / 2;
            if (ok(mid)) {
                low = mid;
            } else {
                hig = mid - 1;
            }
        }
        return low;
    }
};
