class Solution {
public:
    bool hasAllCodes(string s, int k) {
      int n=s.size();
      if(n<k) return false;
      unordered_set<int>st;
    int need=1<<k;
    int mask=need-1;
    int h=0;
    for(int i=0;i<n;i++)
    {
     h=((h<<1)&mask)|(s[i]-'0');
        if(i>=k-1)
        {
            st.insert(h);
        }
      if(st.size()==need)

      {
        return true;
      }

    }
    return false;
    }
};