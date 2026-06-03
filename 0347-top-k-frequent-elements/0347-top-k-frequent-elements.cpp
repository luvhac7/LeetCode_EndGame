class Solution {
public:
    vector<int> topKFrequent(vector<int>& a, int k) {
        unordered_map<int,int>f;int n=a.size();
        for(auto i:a)
        {
            f[i]++;
        }
    vector<vector<int>>temp(n+1);
    for(auto it:f)
    {
        temp[it.second].push_back(it.first);
        cout<<it.second<<" "<<it.first<<"\n";
    }
  //  for(int i=0;i<n;i++){ for(int j=0;j<n;j++) cout<<temp[i][j];}
vector<int>ans;
int cnt=0;
for(int i=n;i>=0;i--)
{
    if(cnt==k) break;
    if(temp[i].size()!=0)
    {
        for(auto it:temp[i])
        {
            ans.push_back(it);cout<<it<<" "<<cnt<<" "<<"\n";
            cnt++;
        }
    }
}
    return ans;
    }
};