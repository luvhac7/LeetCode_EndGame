class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& a) {
        if(a.size()<=1) return a;
        sort(a.begin(),a.end(),[](const vector<int>&x,vector<int>&y)
        {
            return x[0]<y[0];
        });
        vector<vector<int>>ans;
        for(auto &i:a)
        {
            if(ans.empty()||ans.back()[1]<i[0])
            {
                ans.push_back(i);
            }
            else{
                ans.back()[1]=max(ans.back()[1],i[1]);
            }

        }
    return ans;
    }
};