class Solution {
public:
    int area(vector<int>& a) {
        int n = a.size();
        stack<int> st;
        int maxi = 0;
        a.push_back(0);
        for (int i = 0; i <= n; i++) {

            while (!st.empty() && a[i] < a[st.top()]) {
                int ht = a[st.top()];
                st.pop();
                int w = st.empty() ? i : i - st.top() - 1;
                maxi = max(maxi, ht * w);
            }
            st.push(i);
        }
        a.pop_back();
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& a) {
        int m = a.size();
        int n = a[0].size();
        if (a.empty())
            return 0;
        vector<int> hist(n, 0);
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '1') {
                    hist[j] += 1;
                } else {
                    hist[j] = 0;
                }
            }
        
        ans = max(ans, area(hist));
        }
        return ans;
    }
};