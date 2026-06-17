class Solution {
public:
typedef long long ll;
    char processStr(string s, long long k) {
      int n=s.size();
      vector<ll>a;
      ll x=0;
      for(auto &c:s)
      {
        if(c=='*') x=max(x-1,0LL);
        else if (c=='#') x*=2;
        else if(c!='%') x++;
        a.push_back(x);
      }
      if(k>=x) return '.';
      for(int i=n-1;;i--)
      {
        switch(s[i]){
            case '*' :
                break;
            case '#':
                if(k>=a[i]/2)
                    k-=a[i]/2;
                break;
            case '%':
                k=a[i]-1-k;
                break;
            default:
                if(a[i]==k+1)
                    return s[i];
        }
      }
    }
};