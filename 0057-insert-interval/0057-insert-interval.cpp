class Solution {
public:
vector<vector<int>>f( vector<vector<int>>&a)
{
    sort(a.begin(),a.end());
    vector<vector<int>>ans;
    ans.push_back(a[0]);
    for(int i=1;i<a.size();i++)
    {
        vector<int>&cur=a[i];
        vector<int>&end=ans.back();
        if(cur[0]<=end[1])
        {
            end[1]=max(end[1],cur[1]);
        }
        else{
            ans.push_back(cur);
        }
    }
    return ans;
}
    vector<vector<int>> insert(vector<vector<int>>& in, vector<int>& nin) {
        in.push_back(nin);
        return f(in);
    }
};