class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int min_nums = nums[0];
        int max_nums = nums[n - 1];
        set<int> se1,se;
        for(int i = 0; i < n; i++){
            se.insert(nums[i]);
        }
        for(int i = min_nums; i <= max_nums; i++){
            se1.insert(i);
        }
        vector<int> res;
        for(auto x : se1){
            if(!se.count(x)){
                res.push_back(x);
            }
        }
        return res;
    }
};