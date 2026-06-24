class Solution {
public:
bool f(string s)
{
    int n=s.size();
    int i=0,j=n-1;
    while(i<j)
    {
        if(s[i]!=s[j]) return false;
        i++;j++;
    }
    return false;
}
    bool isStrictlyPalindromic(int n) {
        int x=n<<1;
        string s=to_string(x);
        return f(s);
    }
};