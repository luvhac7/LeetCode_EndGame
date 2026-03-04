class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& a) {
        vector<vector<int>>g(n);
        vector<int>in(n,0);
        for(auto &i:a){
            int c=i[0],p=i[1];
            g[p].push_back(c);
            in[c]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0) q.push(i);

        }
            int cnt=0;
            while(!q.empty()){
                int cur=q.front();q.pop();
                cnt++;
                for(int x:g[cur]){
                    in[x]--;
                    if(in[x]==0) q.push(x);
                }
            }
        
    return cnt==n;
    }
};