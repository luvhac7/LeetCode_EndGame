class Solution {
public:
    bool isPalindrome(string s) {
        string ans="";
        for(char c:s)
        {
            if(isalnum(c)){
            ans+=tolower(c);
            }
        }
        string rev(ans.rbegin(),ans.rend());
        return rev==ans;
    }
};