class Solution {
public:
typedef long long ll;
    long long beautifulSubarrays(vector<int>& a) {
        unordered_map<int,ll>mp;
        int px=0;
        ll ans=0;
        mp[0]=1;
        for(int i:a)
        {
            px^=i;//xor check
            ans+=mp[px];
            mp[px]++;
        }
        return ans;
    }
};