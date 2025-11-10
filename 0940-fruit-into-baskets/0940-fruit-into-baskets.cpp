class Solution {
public:
    int totalFruit(vector<int>& fr) {
        map<int, int> bas;
        int ans = 0, l = 0;
        for (int r = 0; r < fr.size(); r++) {
            bas[fr[r]]++;
            while (bas.size() > 2) {
                bas[fr[l]]--;
                if (bas[fr[l]] == 0) {
                    bas.erase(fr[l]);
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
