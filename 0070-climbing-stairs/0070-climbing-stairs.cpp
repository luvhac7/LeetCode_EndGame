class Solution {
public:
    int fib(int n){
        int a=1,b=1;
        for(int i=2;i<=n;i++)
        {
            int sum=a+b;
            swap(b,a);
            swap(sum,a);
        }
        return a;
    }
    int climbStairs(int n) {
        // if(n<3) return n;
        // return climbStairs(n-1)+climbStairs(n-2);
        return fib(n);
    }
};