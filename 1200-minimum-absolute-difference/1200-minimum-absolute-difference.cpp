class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& a) {
        vector<vector<int>>res;
    sort(a.begin(),a.end());
    int mini=INT_MAX;
    for(int i=0;i+1<a.size();i++)
    {
        mini=min(mini,a[i+1]-a[i]);
    }
    for(int i=0;i+1<a.size();i++)
    {
        if(a[i+1]-a[i]==mini)
        {
            res.push_back({a[i],a[i+1]});
        }
    }
    return res;
    }
};