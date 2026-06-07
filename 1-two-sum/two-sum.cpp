class Solution {
public:
    vector<int> twoSum(vector<int>& a, int t) {
        unordered_map<int,int>f;
        for(int i=0;i<a.size();i++)
        {
            int res=t-a[i];
            if(f.find(res)!=f.end())
            {
                return {f[res],i};
            }
            f[a[i]]=i;
        }
        return {};
    }
};