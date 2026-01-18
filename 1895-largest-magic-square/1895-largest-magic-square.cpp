class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& g) {
        int n=g.size(),m=g[0].size();   
        for(int z=min(n,m);z>1;z--)
        {
            for(int x=0;x<=n-z;x++)
            {
                for(int y=0;y<=m-z;y++)
                {
                    int tar=0;
                    for(int j=0;j<z;j++)
                        tar+=g[x][j+y];
                    bool ok=true;
                    for(int i=0;i<z && ok;i++)
                    {
                        int sum=0;
                        for(int j=0;j<z;j++)
                            sum+=g[i+x][j+y];
                            //int sum=0;
                        if(sum!=tar) ok=false;
                    }
                    for(int j=0;j<z;j++)

                    {
                        int sum=0;
                        for(int i=0;i<z;i++)
                            sum+=g[i+x][j+y];
                        if(sum!=tar) ok=false;
                        }
                    int d1=0,d2=0;
                    for(int i=0;i<z;i++)
                    {
                        d1+=g[i+x][i+y];
                        d2+=g[x+i][y+z-i-1];
                    }
                    if(d1!=tar || d2!=tar) ok=false;
                    if(ok) return z; 
                }
            }
        }
        return 1;
    }
};