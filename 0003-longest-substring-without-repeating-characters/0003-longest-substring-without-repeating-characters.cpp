class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size(),cnt=0;
        if(n==0) return 0;
        for(int i=0;i<n;i++)
        {
            vector<bool>v(128,false);
            for(int j=i;j<n;j++){
                if(v[s[j]]) break;
                else{
                    cnt=max(cnt,j-i+1);
                    v[s[j]]=true;
                }
            }
        }
        return cnt;
    }
};