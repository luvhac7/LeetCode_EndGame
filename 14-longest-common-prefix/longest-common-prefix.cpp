class Solution {
public:
static bool cmp(string a,string b)
{
    return a.size()<b.size();
}
    string longestCommonPrefix(vector<string>& s) {
        sort(s.begin(),s.end(),cmp);
      //  for(int i=0;i<s.size();i++) sort(s[i].begin(),s[i].end());
        if(s.empty()) return "";
        for(string i:s) cout<<i<<" ";
        string ans=s[0];
        if(s.size()==1) return s[0];
        for(int i=1;i<s.size();i++)
        {   
            string x=s[i],tmp="";
            for(int j=0;j<x.size() && ans.size();j++)
            { 
                if(x[j]==ans[j]) tmp+=ans[j];
                else break;
            }
            ans=tmp;
            if(ans.empty()) return "";
        }
        return ans;
    }
};