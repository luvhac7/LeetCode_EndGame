class Solution {
public:
bool palind(string s)
{
    int l=0,h=s.size()-1;
    while(l<h){
        if(s[l++]!=s[h--]) return false;
    }
    return true;
}
void back(string s,int idx,vector<vector<string>>&ans,vector<string>&cur)
{
if(idx==s.size()){
    ans.push_back(cur);
    return ;
}
string x="";
for(int i=idx;i<s.size();i++)
{
    x+=s[i];
    if(palind(x))
    {
        cur.push_back(x);
        back(s,i+1,ans,cur);
        cur.pop_back();
    }
}
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>cur;
        back(s,0,ans,cur);
        return ans;
    }
}; 