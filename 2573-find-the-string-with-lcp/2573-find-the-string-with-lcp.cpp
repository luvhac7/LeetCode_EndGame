class Solution {
public:
    bool valid(vector<vector<int>>&lcp, int n){
        if(lcp[0][0]!=n) return false;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(lcp[i][j]!=lcp[j][i]) return false;
                if(lcp[i][j]> (n-max(i,j))) return false;

                if(i+1<n && j+1<n && lcp[i][j] && lcp[i+1][j+1]!=lcp[i][j]-1) return false;
            }
        }
        return true;
    }
    string findTheString(vector<vector<int>>& lcp) {
        int n=lcp.size();

        if(!valid(lcp,n)) return  "";

        string ans(n,' ');
        char curr='a';

        for(int i=0;i<n;i++){
            if(ans[i]!=' ') continue;
            if(curr>'z') return "";

            for(int j=0;j<n;j++){
                if(lcp[i][j]>0) ans[j]=curr;
            }
            curr++;

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x=i,y=j,cnt=0;
                while(x<n && y<n && ans[x]==ans[y]){
                    cnt++;
                    x++,y++;
                }
                if(cnt!=lcp[i][j]) return "";
            }
        }
        return ans;
    }
};