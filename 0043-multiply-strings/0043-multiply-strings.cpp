class Solution {
public:
    string multiply(string a, string b) {
        if(a=="0" || b=="0") return "0";
        int l1=a.size(),l2=b.size();
        vector<int>res(l1+l2,0);
        for(int i=l1-1;i>=0;i--)
        {
            int d1=a[i]-'0';
            for(int j=l2-1;j>=0;j--)
            {
                int d2=b[j]-'0';
                res[i+j+1]+=d1*d2;
            }
        }
        for(int i=res.size()-1;i>0;i--)
        {
            res[i-1]+=res[i]/10;
            res[i]%=10;
        }
        int idx=res[0]==0 ? 1:0;
        string ans="";
        for(int i=idx;i<res.size();i++)
        {
            ans+='0'+res[i];
        }
        return ans;
    }
};