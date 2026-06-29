class Solution {
public:
int cnt=0;
    int numOfStrings(vector<string>& pat, string w) {
        // for(string s:pat)
        // {
        // if(w.find(s)!=std::string::npos) cnt++;    
        //  }
        // return cnt;
        int cnt=0; 
        for(string s:pat)
        {
            bool f=true;
            for(int i=0;i<w.size();i++)
            {
                if((w.substr(i,s.size())==s) && f) {cnt++;f=false;}
            }
        }
        return cnt;
    }
};