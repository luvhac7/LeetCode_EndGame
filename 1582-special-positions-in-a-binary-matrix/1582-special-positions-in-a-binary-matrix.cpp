class Solution {
public:
    int numSpecial(vector<vector<int>>& a) {
        int m=a.size(),n=a[0].size();
        vector<int>row(m),col(n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1)
                {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(row[i]==1 && col[j]==1 && a[i][j]==1)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};