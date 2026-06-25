class Solution {
public:
int is(int n){if(n<2) return false;for(int i=2;i*i<=n;i++)if(!(n%i))return false;return true;}
    int mostFrequentPrime(vector<vector<int>>& a) {
        int n=a.size(),cnt=0,m=a[0].size();
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(is(a[i][j])) cnt++;
        //     }
        // }
        // return cnt;
        map<int,int>f;
        int dx[]={-1,-1,-1,0,0,1,1,1},dy[]={-1,0,1,-1,1,-1,0,1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
            for(int d=0;d<8;d++)
            {
                int r=i,c=j,cur=0;
                while(r>=0 && c>=0 && r<n && c<m)
                {
                    cur=cur*10+a[r][c];
                    if(cur>10 && is(cur)) f[cur]++;
                    r+=dx[d];
                    c+=dy[d];
                }
            }
            }
        }
        int maxi=0,ans=-1;
        for(auto &it:f)
        {
            int prime=it.first,frq=it.second;
            if(frq>maxi){
                maxi=frq;ans=prime;
            }
            else if(frq==maxi)
            {
                ans=max(ans,prime);
            }
        }
        return ans;
    }
};