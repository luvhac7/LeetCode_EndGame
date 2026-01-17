class Solution {
public:
typedef long long ll;
    long long countPairs(vector<string>& words) {
        unordered_map<string,ll>f;
        ll ans=0;
        for(string &w:words)
        {
            string x="";
            int shit=w[0]-'a';
            for(char c:w)
            {
            char nc=(c-'a'-shit+26)%26+'a';
            x.push_back(nc);
            }
            ans+=f[x];
            f[x]++;
        }
        return ans;
    }

};