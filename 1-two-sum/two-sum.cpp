class Solution {
public:
unordered_map<int,int>mp;
    vector<int> twoSum(vector<int>& a, int t) {
        for(int i=0;i<a.size();i++)
        {
            //x=a[i]-t;->3-2=1->1 is there in hashmap
            //if yes then select both pair as ans
            //mp[x],i
            //mp[x]->
            int x=t-a[i];
            if(mp.find(x)!=mp.end())
            {
                return {mp[x],i};
            }
            mp[a[i]]=i;
        }
        return {};
    }
};