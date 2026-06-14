class Solution {
public:
int luv[1005][1005];
int lcs(int i,int j,string &a,string &b)
{
    if(i<0||j<0) return 0;
    if(luv[i][j]!=-1) return luv[i][j];
    if(a[i]==b[j]){
        luv[i][j]=1+lcs(i-1,j-1,a,b);
    }
    else{
        luv[i][j]=max(lcs(i-1,j,a,b),lcs(i,j-1,a,b));
    }
    return luv[i][j];
}
    int longestCommonSubsequence(string a, string b) {
        memset(luv,-1,sizeof(luv));
        return lcs(a.size()-1,b.size()-1,a,b);
    }
};