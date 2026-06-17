class Solution {
public:
    bool isPowerOfTwo(int n) {
    //1.    return n>0 && (n&(n-1))==0;
    // if(n==0) return false;
    // if(n==1) return true;
    // while(n%2==0)
    // {
    //     n/=2;
    // }
    // return n==1;
    for(int i=0;i<=100;i++)
    {
        if(pow(2,i)==n) return true;
    }
    return false;
    }
};