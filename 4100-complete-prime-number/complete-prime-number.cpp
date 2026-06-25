class Solution {
public:
bool p(int n)
{
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}
    bool completePrime(int n) {
        string s=to_string(n);
        for(int i=s.size();i>=1;i--)
        {
            int temp=stoi(s.substr(0,i));
            if(!p(temp)) return false;
        }
        for(int i=0;i<s.size();i++)
        {
            int temp=stoi(s.substr(i));
            if(!p(temp)) return false;
        }
        return true;
    }
};