class Solution {
public:
    typedef long long ll;
    priority_queue<pair<int,int>> pq;
    int maxi(int j) {
        while(!pq.empty() && pq.top().second <= j)
            pq.pop();
        if(pq.empty()) return 0;
        return pq.top().first;
    }

    int maximumRobots(vector<int>& ct, vector<int>& rc, long long budget) {
        int n = rc.size();
        ll sum = 0;
        int j = -1, ans = 0;
        for(int i = 0; i < n; i++) {
            sum += rc[i];
            pq.push({ct[i], i});
            while(maxi(j) + (ll)(i - j) * sum > budget) {
                sum -= rc[++j];
            }
            ans = max(ans, i - j);
        }
        return ans;
    }
};
