class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int>comp(n, -1);
        vector<bool>ans;
        comp[0]=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]-nums[i]<=maxDiff)
            comp[i+1]=comp[i];
            else
            comp[i+1]=comp[i]+1;
        }
        for(auto& q : queries)
{
    int node1 = q[0], node2 = q[1];
    if(comp[node1] == comp[node2])
        ans.push_back(true);
    else
        ans.push_back(false);
}
return ans;
    }
};