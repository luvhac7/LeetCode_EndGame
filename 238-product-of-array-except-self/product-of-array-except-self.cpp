class Solution {
public:
    vector<int> productExceptSelf(vector<int>& a) {
        vector<int> res;
        int totalProductWithoutZero = 1;
        int zeroCount = 0;
        for (int i : a) {
            if (i == 0) {
                zeroCount++;
            } else {
                totalProductWithoutZero *= i;
            }
        }

        for (int i = 0; i < a.size(); i++) {
            if (zeroCount > 1) {
                res.push_back(0);
            } else if (zeroCount == 1) {
                if (a[i] == 0) {
                    res.push_back(totalProductWithoutZero);
                } else {
                    res.push_back(0);
                }
            } else {
                res.push_back(totalProductWithoutZero / a[i]);
            }
        }

        return res;
    }
};
