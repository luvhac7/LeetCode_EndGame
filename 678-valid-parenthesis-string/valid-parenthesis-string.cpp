class Solution {
public:
    bool getans(int idx,string &s,int sum,vector<vector<int>>&dp){
        if(idx==s.size()){
            return sum==0;
        }
        bool ans =false;
        if(dp[idx][200+sum]!=-1)return dp[idx][200+sum];
        if(s[idx]=='('){
           ans= ans ||  getans(idx+1,s,sum+1,dp);
        }else if(s[idx]==')'){
            if(sum>0)ans= ans ||getans(idx+1,s,sum-1,dp);
        }else if(s[idx]=='*'){
          ans= ans ||  getans(idx+1,s,sum+1,dp);
          if(sum>0)ans= ans ||   getans(idx+1,s,sum-1,dp);
          ans= ans ||   getans(idx+1,s,sum,dp);
          
        }
        return dp[idx][200+sum] =  ans;
    }
    bool checkValidString(string s) {
        vector<vector<int>>dp(s.size(),vector<int>(501,-1));
        return getans(0,s,0,dp);
    }
};