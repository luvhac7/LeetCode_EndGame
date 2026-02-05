class Solution {
public:
    int beautySum(string s) {

        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            vector<int>f(26);

            for(int j=i;j<s.size();j++){
            f[s[j]-'a']++;
            int mini=INT_MAX,maxi=0;
            for(int x:f)
            {
                if(x>0){
                maxi=max(maxi,x);
                mini=min(mini,x);
                }
            }
            
            ans+=(maxi-mini);
        }
        }
        return ans;
    }
};