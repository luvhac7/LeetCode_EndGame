    class Solution {
    public:
        int minGroups(vector<vector<int>>& a) {
            map<int,int>mp;
            for(auto &i:a)
            {
                mp[i[0]]++;
                mp[i[1]+1]--;
            }
            int cur=0,ans=0;
            for(auto &i:mp)
            {
                cur+=i.second;
                ans=max(ans,cur);
            }
            return ans;
        }
    };