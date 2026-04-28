class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(), m = grid[0].size();
        vector<int> nums;
        nums.reserve(n * m);

        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                int curr = grid[i][j];
                nums.push_back(curr);
            }
        }

        std::sort(nums.begin(), nums.end());
        int mid = nums.size() / 2;
        int count = 0;
        int prev = nums[0];
        for(int i = 0; i < nums.size(); ++i)
        {
            if(i > 0 && abs(nums[i] - prev) % x > 0)
                return -1;

            count += (abs(nums[mid] - nums[i]) / x);
            prev = nums[i];
        }
        
        return count;
    }
};