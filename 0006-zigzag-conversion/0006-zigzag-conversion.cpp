class Solution {
public:
    string convert(string s, int n) {
        string ans;
        vector<vector<char>>row(n);
        int k=0;
        int d=(n==1)-1;
        for(char c:s)
        {
            
            row[k].push_back(c);
            if(k==0 || k==n-1)
            {
                d*=-1;
              
            }
            k+=d;
        }
        for(vector<char>&i:row)
        {
            for(char c:i)
            {
                ans+=c;
            }
        }
        return ans;
    }
};