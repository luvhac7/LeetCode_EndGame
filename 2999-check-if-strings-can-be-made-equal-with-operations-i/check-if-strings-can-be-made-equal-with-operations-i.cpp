class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string even1 = "";
        even1 += s1[0];
        even1 += s1[2];
        string even2 = "";
        even2 += s2[0];
        even2 += s2[2];
        sort(even1.begin(), even1.end());
        sort(even2.begin(), even2.end());

        if (even1 != even2) {
            return false;
        }
        string odd1 = "";
        odd1 += s1[1];
        odd1 += s1[3];
        string odd2 = "";
        odd2 += s2[1];
        odd2 += s2[3];
        sort(odd1.begin(), odd1.end());
        sort(odd2.begin(), odd2.end());
        
        if (odd1 != odd2) {
            return false;
        }

        return true;
    }
};
