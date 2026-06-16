class Solution {
public:
string res;    
    string processStr(string s) {
    for(char c:s)
    {
        if(c=='*'){
            if(res.size()) res.pop_back();
        }
        else if(c=='#') res+=res;
        else if(c=='%') reverse(res.begin(),res.end());
        else res+=c;
    }
    return res;
        
    }
};