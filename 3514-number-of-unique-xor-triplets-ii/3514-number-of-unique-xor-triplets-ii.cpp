class Solution {
public:
    int uniqueXorTriplets(vector<int>& a) {
    unordered_set<int>ans,res;
    int n=a.size();
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            ans.insert(a[i]^a[j]);
        }
    }
    for(auto i:ans)
    {
        for(auto j:a)
        {
            res.insert(i^j);
        }
    }
    return res.size();
    }
};