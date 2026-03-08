class Solution {
public:
bool is(string s)
{
int i=0,j=s.size()-1;
while(i<j)
{
    if(s[i++]!=s[j--]) return false;
}
return true;
}
void dfs(string s,vector<vector<string>>&res,vector<string>&cur,int idx)
{
    if(idx==s.size()){
        res.push_back(cur);return;
    }
    string x="";
    for(int i=idx;i<s.size();i++)
    {
        x+=s[i];
        if(is(x))
        {
            cur.push_back(x);
            dfs(s,res,cur,i+1);
            cur.pop_back();
        }
    }
}
    vector<vector<string>> partition(string s) {
        vector<string>a;
        vector<vector<string>>b;
        dfs(s,b,a,0);
        return b;
    }
};