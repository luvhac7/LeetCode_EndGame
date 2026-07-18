class Solution {
public:
    int findGCD(vector<int>& a) {
        int x=*min_element(a.begin(),a.end());
        int y=*max_element(a.begin(),a.end());
        return __gcd(x,y);
    }
};