class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        ans.reserve(nums.size());
        int c= 0;

        for (int b : nums) {
            c = ((c<< 1) + b) % 5;
            ans.push_back(c == 0);
        }

        return ans;
    }
};
