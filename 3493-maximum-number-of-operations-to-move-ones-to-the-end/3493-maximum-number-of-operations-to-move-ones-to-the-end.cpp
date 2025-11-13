class Solution {
public:
    int maxOperations(string s) {
       // int ones=count(s.begin(),s.end(),'1');
        int ones=0;
        int ans=0,n=s.size();
        for(int i=0;i<n;i++)
        {
        if(s[i]=='1'){
            ones++;
        }

           else if(s[i+1]=='1' || i+1==n)
           {
            ans+=ones;
           }
        }
        return ans;
    }
};