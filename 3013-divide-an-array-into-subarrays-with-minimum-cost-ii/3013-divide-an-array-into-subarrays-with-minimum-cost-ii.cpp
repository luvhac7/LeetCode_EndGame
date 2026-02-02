using ll = long long;

class Solution {
public:
    ll minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        ll sum = 0;
        ll best = LLONG_MAX;
        multiset<int, greater<int>> top, bot;

        for (int r = 1; r < n; r++) {
            int l = r - dist - 1;
            if (l >= 1) {
                if (top.contains(nums[l])) {
                    sum -= nums[l];
                    top.erase(top.find(nums[l]));
                }

                if (bot.contains(nums[l]))
                    bot.erase(bot.find(nums[l]));
            }

            sum += nums[r];
            top.insert(nums[r]);

            if (top.size() > (k - 1)) {
                sum -= *top.begin();

                bot.insert(*top.begin());
                top.erase(top.begin());
            }

            while (top.size() && bot.size() &&
                   (*top.begin() > *prev(bot.end()))) {
                sum -= *top.begin();
                sum += *prev(bot.end());

                bot.insert(*top.begin());
                top.erase(top.begin());

                top.insert(*prev(bot.end()));
                bot.erase(prev(bot.end()));
            }

            if (top.size() == (k - 1))
                best = min(best, sum);
        }

        return nums[0] + best;
    }
};