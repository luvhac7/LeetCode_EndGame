class Solution {
public:
    int uniqueXorTriplets(vector<int>& a) {
        int n=a.size();
        if(n<3)return n;
        return 1<<static_cast<int>(log2(n)+1);
    }
};