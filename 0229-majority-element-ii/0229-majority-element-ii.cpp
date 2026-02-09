class Solution {
public:
    vector<int> majorityElement(vector<int>& a) {
        unordered_map<int,int>mp;
        for(int i:a) mp[i]++;
        int n=a.size();
        vector<int>ans;
        for(auto i:mp)
        {
            if(i.second>n/3){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};