class Solution {
public:
    static bool cmp(pair<int,int>&A,pair<int,int>&B)
    {
        if(A.second!=B.second) return A.second<B.second;
        return A.first>B.first;
    }
vector<int>frequencySort(vector<int>&a)
{
    map<int,int>f;for(int i:a) f[i]++;
    vector<pair<int,int>>ans(f.begin(),f.end());
    sort(ans.begin(),ans.end(),cmp);
    vector<int>res;
    for(auto i:ans)
    {
        res.insert(res.end(),i.second,i.first);
    }
    return res;
}
};
