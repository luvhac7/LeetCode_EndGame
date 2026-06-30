class Solution {
public:
    typedef vector<string> vs;

    vs find_substr(string s) {
        int n = s.size();
        vs res;
        for (int i = 0; i < n; i++) {
            for (int len = 1; len <= n - i; len++) {
                string sub = s.substr(i, len);
                res.push_back(sub);
            }
        }
        return res;
    }

    int numberOfSubstrings(string s) {
        int n=s.size(),cnt=0;
        size_t pos=s.find("abc",0);
        while(pos!=string::npos)
        {
            pos=s.find("abc",pos+1);
        }
        int a=-1,b=-1,c=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')a=i;
            if(s[i]=='b')b=i;
            if(s[i]=='c')c=i;
            if((a!=-1 && b!=-1 && c!=-1)) cnt+=(min({a,b,c}))+1;
        }
return cnt;
    }
};
