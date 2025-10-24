class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n = a.size();
        if (n == 0) return 0;

        int idx = 0; // Unique elements ka index
        for (int i = 1; i < n; i++) {
            if (a[i] != a[idx]) {  // New unique element mila
                idx++;
                a[idx] = a[i]; // Move unique element forward
            }
        }
        return idx + 1; // New length return karo
    }
};
