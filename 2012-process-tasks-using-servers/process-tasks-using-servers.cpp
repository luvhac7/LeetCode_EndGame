class Solution {
public:
    using ll= long long;
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();
        vector<int> ans(m);
        priority_queue<vector<ll>, vector<vector<ll>>, greater<vector<ll>>>
            time;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>
            wts;
        for (int i = 0; i < n; i++)
            time.push({0, i});
        vector<ll> dist(n, 0);
        for (int j = 0; j < m; j++) {
            ll mint = time.top()[0];
            if (!wts.empty() || mint <= j) {
                while (!time.empty() && time.top()[0] <= j) {
                    int id = time.top()[1];
                    time.pop();
                    wts.push({servers[id], id});
                }
                int minw = wts.top()[1];
                wts.pop();
                ans[j] = minw;
                dist[minw] = tasks[j] + max(1LL*j, dist[minw]);
                time.push({dist[minw], minw});
            } else {
                while (!time.empty() && time.top()[0] == mint) {
                    int id = time.top()[1];
                    time.pop();
                    wts.push({servers[id], id});
                }
                int minw = wts.top()[1];
                wts.pop();
                ans[j] = minw;
                dist[minw] += tasks[j];
                time.push({dist[minw], minw});
            }
        }
        return ans;
    }
};