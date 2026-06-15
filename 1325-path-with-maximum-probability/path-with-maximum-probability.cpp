class Solution {
public:
double solve(int n,vector<vector<int>>&ed,vector<double>&pro,int start,int end)
{
    vector<vector<pair<int,double>>>g(n);
for(int i=0;i<ed.size();i++)
{
g[ed[i][0]].push_back({ed[i][1],pro[i]});
g[ed[i][1]].push_back({ed[i][0],pro[i]});
}
vector<int>seen(n,0);
priority_queue<pair<double,int>>q;
q.push({(double)1.0,start});
vector<double>mx(n,(double)0.0);
mx[start]=1.0;
while(!q.empty())
{
    auto top=q.top();
    q.pop();
    double prob=top.first;
    int node=top.second;
    if(!seen[node])
    {
        seen[node]++;
    for(auto &it:g[node])
    {
    if(mx[it.first]<it.second*prob)
    {
        mx[it.first]=it.second*prob;
        q.push({mx[it.first],it.first});
    }
    }
    }
}
return mx[end];
}
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        return solve(n,edges,succProb,start_node,end_node);
    }
};