class Solution {
public:
    int firstUniqChar(string s) {
      map<char,int>f;
      for(char c:s) f[c]++;
        for(int i=0;i<s.size();i++)
        {
            if(f[s[i]]==1)
            {
                return i;
            }
        }
        return -1;
    }
};