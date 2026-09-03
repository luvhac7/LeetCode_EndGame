class Solution {
public:
    bool uniformArray(vector<int>& a) {
        int mini=1e9+7,o=0;
        for (int x : a) {
            mini= min(mini,x);
            if (x%2 == 1)o++;
        }
        return mini%2||o==0;
    }
};