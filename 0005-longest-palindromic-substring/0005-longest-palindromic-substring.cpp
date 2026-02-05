class Solution {
public:

    int ex(string s,int l,int r)
    {
        while(l>=0 && r<s.size() && s[l]==s[r])
        {
            l--;r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        if(s.empty()) return " ";
       int len=0,end=0,n=s.size(),st=0;
    for(int i=0;i<n;i++)
    {
//"babad"
//odd->a a
//even->b b d
//len=3
//3>0->i=0 ->
        int odd=ex(s,i,i);//
        int even=ex(s,i,i+1);
        int len=max(odd,even);
        if(len>end-st)
        {
            st=i-(len-1)/2;//->i=0-(3-1)/2=1
            end=i+(len/2);//->i0+(3/2)=1.5=2//1->st,end->()
        }
    }
    return s.substr(st,end-st+1);

        }
};