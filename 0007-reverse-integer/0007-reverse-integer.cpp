class Solution {
public:
typedef long long ll;
    int reverse(int x) {
        ll n=0;
        while(x!=0)
        {
            int d=x%10;
            n=10*n+d;
            if(n>INT_MAX || n<INT_MIN)  return 0;
            x=x/10;
        }
        return (int)n;
    }
};