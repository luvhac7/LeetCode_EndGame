class Solution {
public:
void solve(string s,vector<string>&res,unordered_set<string>&st,vector<string>&temp)
{
    if(s.size()==0){
        string str="";
        for(auto it:temp){
            str+=it+" ";
        }
        str.pop_back();
        res.push_back(str);
        return;
    }
    for(int i=0;i<s.size();i++)
    {
    if(st.count(s.substr(0,i+1))){
        temp.push_back(s.substr(0,i+1));
        solve(s.substr(i+1),res,st,temp);
        temp.pop_back();
    }
    }
}

    vector<string> wordBreak(string s, vector<string>& wd) {
vector<string>res,temp;
unordered_set<string>st(wd.begin(),wd.end());
solve(s,res,st,temp);
return res;
    }
};