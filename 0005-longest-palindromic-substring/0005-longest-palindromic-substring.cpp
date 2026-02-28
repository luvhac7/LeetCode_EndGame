class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size(),st=0,len=1;
        for(int i=0;i<n;i++)
        {
            //odd
            int l=i,h=i;
            while(l>=0 && h<n && s[l]==s[h])
            {
                if(h-l+1>len)
                {
                    len=h-l+1;
                    st=l;
                }
                h++;
                l--;
            }
              l=i,h=i+1;
             while(l>=0&&h<n&&s[l]==s[h])
             {
                if(h-l+1>len)
                {
                    len=h-l+1;
                    st=l;
                }
                l--;h++;
             }
        }
        return s.substr(st,len);
    }
};