class Solution {
public:
    bool checkDivisibility(int n) {
        int ks =n; 
        int sum = 0; 
        int prod = 1; 
        while(n>0){
            int digit = n%10; 
            sum += digit; 
            prod *= digit;
            n/=10;
        }
        int total = sum +prod ;
        return ks%total==0;
    }
};