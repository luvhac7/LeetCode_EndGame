class Solution {
public:
    int countBinarySubstrings(string s) {
        int x=s.size(),p=0;
        vector<int>res;
        while(p<x)
        {
            int cnt=1;
            while(p+1<x&&s[p+1]==s[p])
            {
                cnt++;p++;
            }
            res.push_back(cnt);
            p++;
        }
        int ans=0;
        for(int i=1;i<res.size();i++)
        {
            ans+=min(res[i-1],res[i]);
        }
        return ans;
    }
};