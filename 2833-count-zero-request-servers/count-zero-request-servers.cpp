class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin() , logs.end() , [](const vector<int>&a , const vector<int>& b){return a[1] < b[1];});
        vector<int> time(logs.size()) , server(logs.size());
        for(int i=0;i<logs.size();i++){
            time[i] = logs[i][1];
            server[i] = logs[i][0];
        }
        vector<vector<int>> upd_que(queries.size());
        for(int i=0;i<queries.size();i++){
            upd_que[i] = {queries[i] , i};
        }
        sort(upd_que.begin() , upd_que.end());
        vector<int> ans(queries.size());
        int c = 0; map<int,int> m; int l = 0 , r = 0 , prev_l= 0 , prev_r =0;
        for(int i=0;i<queries.size();i++){
            int a = upd_que[i][0] - x;
            int l = lower_bound(time.begin(),time.end(),a) - time.begin();
            int r = upper_bound(time.begin(),time.end(),upd_que[i][0]) - time.begin();
            r--;
            if(i==0){
                for(int k=l;k<=r;k++){
                    if(m[server[k]]==0)c++;
                    m[server[k]]++;
                }
            }
            else{
                for(int k = prev_l;k<=min(prev_r,l-1);k++){
                    m[server[k]]--;
                    if(m[server[k]]==0)c--;
                }
                for(int k = max(prev_r+1,l);k<=r;k++){
                    if(m[server[k]]==0)c++;
                    m[server[k]]++;
                }
            }
            ans[upd_que[i][1]] = n - c;
            prev_l = l , prev_r = r;
        }
        return ans;
    }
};