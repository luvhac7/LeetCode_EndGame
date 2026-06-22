class Solution {
public:
typedef vector<vector<int>> vii;
typedef vector<int> vi;
    bool canFinish(int n, vector<vector<int>>&a) {
        vii node(n);
        vi indegree(n,0);
        for(auto &it:a)
        {
            int cource=it[0],pre=it[1];
            node[pre].push_back(cource);
            indegree[cource]++;
        }
        queue<int>qu;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) qu.push(i);
        }
        int count=0;
        while(!qu.empty())
        {
            int curr=qu.front();qu.pop();
            count++;
            for(int it:node[curr])
            {
                indegree[it]--;
                if(indegree[it]==0) qu.push(it);
            }
        }
        return count==n;
    }
};