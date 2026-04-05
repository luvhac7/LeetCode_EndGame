class Solution {
public:
    bool judgeCircle(string a) {
        if(a.size()&1) return false;
        int u=0,d=0,l=0,r=0;
        for(char c:a)
        {
            u+=c=='U',d+=c=='D',l+=c=='L',r+=c=='R';
        }
        return u==d && l==r;
    }
};