class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        //dp ka table create karta hu
        //n+1 m+1 size ka
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        //string ko row col me store kartna 
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=i;
        }
        for(int i=0;i<=m;i++)
        {
            dp[0][i]=i;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]+=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
                }
            }
        }
        return dp[n][m];
      /*  
        if(n==1 && m==1 ) return 0;
        if(n==1 || m==1) return 1;
        if(n==m) return (n+1)/2;
        int cnt=0;
    if(n>m){
        for(int i=0;i<n;i++)
        {
            if(word1[i]!=word2[i])
            {
                word1[i]=word2[i];
                cnt++;
            }
        }
        if(m>n)
        {
            for(int i=0;i<n;i++)
            {
                cnt++;
                word1[i]=word2[i];
            }   
        }
    }
        return word2.size();
        */
    }
};