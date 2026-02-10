class Solution {
public:
    int findMin(vector<int>& a) {
        sort(a.begin(),a.end());
        return a[0];
    }
};