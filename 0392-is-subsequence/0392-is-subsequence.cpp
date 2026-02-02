class Solution {
public:
    bool isSubsequence(string s, string t) {
        int k = 0;

        for (int i = 0; i < t.size(); i++) {
            if (k < s.size() && t[i] == s[k]) {
                k++;
            }
        }

        return k == s.size();
    }
};
