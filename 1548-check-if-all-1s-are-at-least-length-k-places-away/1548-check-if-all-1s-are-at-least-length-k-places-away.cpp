class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int> ans;
        int cnt = 0;
        bool seenOne = false;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 1) {
                if (seenOne) {          // we already saw a previous 1
                    ans.push_back(cnt); // store gap
                }
                cnt = 0;
                seenOne = true;
            }
            else { 
                if (seenOne) cnt++;     // count zeros only after first 1
            }
        }

        // check all gaps
        for (int x : ans) {
            if (x < k) return false;
        }

        return true;
    }
};
