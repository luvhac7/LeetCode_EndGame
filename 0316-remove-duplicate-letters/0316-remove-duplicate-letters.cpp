class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>f(26,0);
        for(char c:s) f[c-'a']++;
        vector<bool>use(26,false);
        string ans;
        for(char c:s)
        {
            f[c-'a']--;
            if(use[c-'a']) continue;
            while(!ans.empty() && ans.back()>c && f[ans.back()-'a']>0)
            {
                use[ans.back()-'a']=false;
                ans.pop_back();
            }
            ans.push_back(c);
            use[c-'a']=true;
        }
    return ans;
    }


};