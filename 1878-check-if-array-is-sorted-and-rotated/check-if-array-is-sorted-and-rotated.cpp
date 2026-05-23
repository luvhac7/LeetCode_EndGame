class Solution {
public:
    bool check(vector<int>& a) {
        int n=a.size();
        int cnt=0;
        for(int i=1;i<a.size();i++)
        {
            if(a[i-1]>a[i]) cnt++;
        }
        if(a[0]<a[n-1]) cnt++;
        return cnt<=1;
    }
};