class Solution {
public:
    int minimumDistance(vector<int>& a) {
       map<int,vector<int>>mp;
       for(int i=0;i<a.size();i++)
       {
        mp[a[i]].push_back(i);
       }
       int ans=1e9;
       for(auto i:mp)
        {
            vector<int>v=i.second;
            if(v.size()>=3)
            {
                for(int i=0;i<=v.size()-3;i++)
                {
            int d=abs(v[i]-v[i+1])+abs(v[i]-v[i+2])+abs(v[i+1]-v[i+2]);
            ans=min(ans,d);
                }
            }
        }
        if(ans==1e9) return -1;
        return ans;
    }
};