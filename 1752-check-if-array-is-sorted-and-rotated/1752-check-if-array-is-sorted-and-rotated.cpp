class Solution {
public:
    bool check(vector<int>& a) {
        int n=a.size();
        int cnt=0;
        for(int i=1;i<n;i++)
            if(a[i-1]>a[i])
                cnt++;
        if(a[n-1]>a[0])
            cnt++;
        return cnt<=1;
    }
};