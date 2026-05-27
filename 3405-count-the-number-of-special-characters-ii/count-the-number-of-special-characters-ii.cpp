class Solution {
public:
    int numberOfSpecialChars(string w) {
        vector<int>last(26,-1),first(26,-1);
        for(int i=0;i<w.size();i++)
        {
            char c=w[i];
            if(islower(c))
            {
                last[c-'a']=i;
            }
            else{
                if(first[c-'A']==-1)
                {
                    first[c-'A']=i;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<26;i++)
        {
            if(last[i]!=-1 && first[i]!=-1 && last[i]<first[i])
            {
                cnt++;
            }
        }
        return cnt;
    }
};