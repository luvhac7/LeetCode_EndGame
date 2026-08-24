class Solution {
public:
    int stoneGameVIII(vector<int>& a) {
        int n = a.size();
        for (int i = 1; i < n; i++) {
            a[i] += a[i - 1];
        }
        int bst=a[n - 1];
        for (int i = n - 2; i >= 1; i--) {
            bst= max(bst,a[i]-bst);
        }
        return bst;
    }
};