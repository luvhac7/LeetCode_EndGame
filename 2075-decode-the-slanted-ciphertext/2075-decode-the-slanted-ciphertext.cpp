class Solution {
public:
    string decodeCiphertext(string a, int n) {
        int l=a.size();
        if(l==0) return"";
        int m=l/n;
        string ans="";
        for(int j=0;j<m;j++)
        {
            for(int r=0,c=j;r<n && c<m;r++,c++)
            {
                ans.push_back(a[r*m+c]);
            }
        }
        while(!ans.empty() && ans.back()==' ')
        {
            ans.pop_back();
        }
        return ans;
    }
};