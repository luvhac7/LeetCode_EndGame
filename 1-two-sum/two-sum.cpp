class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        int n=a.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            int x=t-a[i];
            if(mp.find(x)!=mp.end())
            {
                return {mp[x],i};
            }
            mp[a[i]]=i;
        }
        return {-1,-1};
        
    }
};