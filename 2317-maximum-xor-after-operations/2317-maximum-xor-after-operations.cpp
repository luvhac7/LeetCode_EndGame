class Solution {
public:
    int maximumXOR(vector<int>& a) {
        return reduce(a.begin(),a.end(),0,bit_or());
    }
};