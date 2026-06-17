class Solution {
public:
int solve(int n,vector<int>&a)
{if(n<=2) return n;
if(a[n]!=-1) return a[n];
a[n]=solve(n-1,a)+solve(n-2,a);
return a[n];
}
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int>a(n+1,-1);
       return solve(n,a);
    }
};