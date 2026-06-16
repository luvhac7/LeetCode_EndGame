class Solution {
public:
    bool equalFrequency(string a) { 
        int f[26]={0};
        for(char c:a)
        {
            f[c-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(!f[i]) continue;
            f[i]--;
            set<int>st;
            for(int x:f)
            {
                if(x) st.insert(x);
            }
            if(st.size()==1) return true;
            f[i]++;
        }
        return false;
    }
};