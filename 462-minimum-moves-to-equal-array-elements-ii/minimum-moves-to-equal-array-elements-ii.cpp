class Solution {
public:
typedef long long ll;
    int minMoves2(vector<int>& a) {
        int n=a.size();
        sort(a.begin(),a.end());
        int y=a[n/2];
        ll x=0;
        for(int i:a){
             x+=abs(i-y);
        }
    return x;
    }
};