class Solution {
public:
    bool isPowerOfTwo(int n) {
    //1.    return n>0 && (n&(n-1))==0;
    if(n==0) return false;
    if(n==1) return true;
    while(n%2==0)
    {
        n/=2;
    }
    return n==1;
    }
};