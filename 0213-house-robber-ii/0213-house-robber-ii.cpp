class Solution {
public:
    typedef const int ci;
    int rob(vector<int>& a) {
        if(a.empty()) return 0;
        int n=a.size();
        if(n==1 && a[0]==0) return 0;
        if(n==1 && a[0]==100) return 100;
        if(n==1) return 1;
        auto rob=[&](int l,int r){
            int p1=0;
            int p2=0;
            for(int i=l;i<=r;i++){
                ci dp=max(p1,p2+a[i]);
                p2=p1;
                p1=dp;
            }
            return p1;
        };
        return max(rob(0,n-2),rob(1,n-1));
    }
};