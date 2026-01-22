class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n=a.size(),m=a[0].size();
        bool col0=false;
        for(int i=0;i<n;i++)
        {
            if(a[i][0]==0) col0=true;
            for(int j=1;j<m;j++)
            {
                if(a[i][j]==0){
                    a[i][0]=0;
                    a[0][j]=0;
                }
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=1;j--)
            {
                if(a[i][0]==0 || a[0][j]==0)
                {
                    a[i][j]=0;
                }

            }
            if(col0) a[i][0]=0;

        }
    }
};