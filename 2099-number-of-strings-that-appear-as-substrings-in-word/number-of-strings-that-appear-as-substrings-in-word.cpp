class Solution {
public:
int cnt=0;
    int numOfStrings(vector<string>& pat, string w) {
        for(string s:pat)
        {
        if(w.find(s)!=std::string::npos) cnt++;    
         }
        return cnt;
    }
};