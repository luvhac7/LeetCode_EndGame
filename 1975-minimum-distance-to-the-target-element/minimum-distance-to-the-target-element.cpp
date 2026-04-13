class Solution {
public:
    int getMinDistance(vector<int>& a, int t, int st) {
        int res=a.size();
        for(int i=0;i<a.size();i++)
        {
            if(a[i]==t)
            {
                res=min(res,abs(i-st));
            }
        }
        return res;
    }
};