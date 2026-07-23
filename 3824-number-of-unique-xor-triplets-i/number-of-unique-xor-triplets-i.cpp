class Solution {
public:
    int uniqueXorTriplets(vector<int>& a) {
        int n=a.size(),x=1;if(n<3) return n;
        while(x<=n)x<<=1; 
        return x;
    }
};