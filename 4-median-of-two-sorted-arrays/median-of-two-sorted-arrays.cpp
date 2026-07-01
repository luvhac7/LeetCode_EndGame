class Solution {
public:
typedef vector<int> vi;
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        vi f=a;
        for(int i=0;i<b.size();i++) f.push_back(b[i]);
        sort(f.begin(),f.end());
        double x=0;
          int n = f.size();
        if (n % 2 != 0) {
            return f[n / 2];
        } else {
            return (f[(n / 2) - 1] + f[n / 2]) / 2.0;
        }
    }
};