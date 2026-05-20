class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> resp;
        int n = 0;
        for (int j = 0; j < A.size(); j++) {
            int v = j;
            while (v >= 0) {
                for (int z = 0; z <= j; z++) {
                    if (A[v] == B[z]) n++;
                }
                v--;
            }
            resp.push_back(n);
            n = 0;
        }
        return resp;
    }
};