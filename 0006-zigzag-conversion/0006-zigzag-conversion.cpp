class Solution {
public:
    string convert(string s, int n) {
        if(s.empty()|| n<=0) return "";
        if(n==1) return s;
        string res="";
        int st=2*n-2;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<s.size();j+=st)
            {
                res.push_back(s[j]);
                int d=j+st-2*i;
            if(i && i!=n-1 && d<s.size()){
                res.push_back(s[d]);
            }
            }
        }
        return res;
    }
};