class Solution {
public:
string res;
void dfs(int op,int cp,string s,int n,vector<string>&res)
{
    if(op==cp && op+cp==n*2){
        res.push_back(s);
        return;
    }
    if(op<n)
    {
        dfs(op+1,cp,s+"(",n,res);
    }
    if(cp<op){
        dfs(op,cp+1,s+")",n,res);
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        dfs(0,0,"",n,res);
        return res;
    }
};