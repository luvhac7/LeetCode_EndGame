class Solution {
public:
    bool isGoodArray(vector<int>&a) {
        int x=a[0];
        for(int i:a) x=gcd(x,i);
        return x==1;
    }
};