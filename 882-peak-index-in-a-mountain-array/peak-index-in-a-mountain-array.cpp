class Solution {
public:
    int peakIndexInMountainArray(vector<int>& a) {
        return max_element(a.begin(),a.end())-a.begin();
    }
};