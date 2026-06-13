class Solution {
public:
    int findPairs(vector<int>&a, int k) {
        //if(k==0) return 1;
        unordered_map<int,int>f;
        for(int i:a)f[i]++;
        // for(auto &it:f)
        // {
        //     cout<<it.first<<" ";
        //     ans.push_back(it.first);
        // }
        // return k%2==0 ?ans.size()/k :ans.size()/k -1 ;
        int ans=0;
        for(auto &[n,cnt]:f)
        {
            ans+=k ? f.count(n-k):cnt>1;
        }
        return ans;
    }
};