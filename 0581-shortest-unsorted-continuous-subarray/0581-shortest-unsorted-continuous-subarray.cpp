class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        // Step 1: collect all unsorted violations
         for (int i = 1; i < n; i++) {
            if (nums[i] < nums[i - 1]) {
                ans.push_back(nums[i]);
                ans.push_back(nums[i - 1]);
            }
        }

        // If no violations → already sorted
        if (ans.empty()) return 0;

        // Step 2: sort the problematic values
        sort(ans.begin(), ans.end());
        int mn = ans.front();
        int mx = ans.back();

        // Step 3: expand to correct boundaries
        int left = 0, right = n - 1;

        while (left < n && nums[left] <= mn) left++;
        while (right >= 0 && nums[right] >= mx) right--;

        return right - left + 1;
    }
};
