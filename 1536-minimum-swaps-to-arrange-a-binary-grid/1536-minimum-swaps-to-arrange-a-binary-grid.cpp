class Solution {
public:
    int minSwaps(vector<vector<int>>& g) {
        int n=g.size();
        vector<int>z(n);for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=n-1;j>=0&&g[i][j]==0;j--)
            {
                cnt++;
            }
            z[i]=cnt;
        }
        int sw=0;
        for(int i=0;i<n;i++)
        {
            int need=n-i-1;
            int f=-1;
            for(int j=i;j<n;j++)
            {
                if(z[j]>=need)
                {
                    f=j;
                    break;
                }
            }
            if(f==-1)
            {
                return -1;
            }
            for(int j=f;j>i;j--)
            {
                swap(z[j],z[j-1]);
                sw++;
            }
        }
        return sw;
    }
};