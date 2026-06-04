class Solution {
public:
    int totalWaviness(int a, int b) {
        int r=0;
        for(int x=a;x<=b;x++)
        {
            string s=to_string(x);
            for(int i=1;i+1<s.size();i++)
            {
                if((s[i]<s[i-1]&&s[i]<s[i+1])||(s[i]>s[i+1]&&s[i]>s[i-1])) r++;
            }
        }
        return r;
    }
};