class Solution {
public:
    vector<int> solveQueries(vector<int>& a, vector<int>& q) {
    int n=a.size();
    unordered_map<int,vector<int>>mp;
    for(int i=0;i<n;i++) mp[a[i]].push_back(i);
    vector<int>bst(n,INT_MAX);
    for(auto &i:mp)
    {
        vector<int>&lst=i.second;
        int size=lst.size();
        if(size==1)
        {
            bst[lst[0]]=-1;
            continue;
        }
        for(int i=0;i<size;i++)
        {
            int cur=lst[i];
            int prev=lst[(i-1+size)%size];
            int nxt=lst[(i+1)%size];
            int dist=abs(cur-prev);
            dist=min(dist,n-dist);
            int dn=abs(cur-nxt);
            dn=min(dn,n-dn);
            bst[cur]=min(dist,dn);
        }

    }
    vector<int>ans;
    for(int i:q)
    {
        ans.push_back(bst[i]);
    }
    return ans;
    }
};