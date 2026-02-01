class Solution {
public:
typedef long long ll;
bool f(int n)
{
    if(n%2==0) return true;
    return false;
}
    long long numberOfWays(string s) {
       ll a=0,b=0,ans=0;
       for(int i=0;i<s.size();i++)
       {
        if(s[i]=='1') a++;
        else b++;
       }
       ll c=0,d=0;
       for(int i=0;i<s.size();i++)
       {
        if(s[i]=='1')
        {
            ans+=(d*b);
            a--;
            c++;
        }
        else{
            ans+=(c*a);
            b--;
            d++;
        }
       }
       return ans;
    }
};