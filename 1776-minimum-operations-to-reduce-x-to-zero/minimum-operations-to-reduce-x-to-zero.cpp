class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        int n = a.size();
        unordered_map<int,int> mp;
        int sum = 0;
        int ans = INT_MIN;
        int target=0;
        mp[0]=-1;
        for(auto xx : a )
        {
            target+=xx;
            
        }
        target-=x;
        for(int i = 0;i<a.size();i++)
        {
            sum+=a[i];
            mp[sum]=i;
            if(mp.find(sum-target)!=mp.end())
            {
                ans = max(ans,i-mp[sum-target]);
            }

        }
        if(ans==INT_MIN) return -1;
        return n-ans;
        
    }
};