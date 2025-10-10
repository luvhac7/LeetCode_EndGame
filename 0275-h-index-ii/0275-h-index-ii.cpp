class Solution {
public:
    int hIndex(vector<int>& c) {
        int n=c.size();
        int idx=0;
        for(int i=0;i<n;i++)
        {
            int p=n-i;
            if(p<=c[i])
            {
                idx=p;
                break;
            }
        }
        return idx;
    }
};