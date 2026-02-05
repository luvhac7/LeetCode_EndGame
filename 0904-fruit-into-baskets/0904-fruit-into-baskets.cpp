class Solution {
public:
    int totalFruit(vector<int>& a) {
        unordered_map<int,int>mp;int n=a.size(),l=0,ans=0;
        for(int r=0;r<n;r++){
            mp[a[r]]++;
            while(mp.size()>2)
            {
                mp[a[l]]--;
                if(mp[a[l]]==0)
                {
                    mp.erase(a[l]);
                }
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};