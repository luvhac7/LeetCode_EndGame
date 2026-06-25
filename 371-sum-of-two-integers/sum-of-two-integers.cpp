class Solution {
public:
    int getSum(int a, int b) {
       while(b)
       {
        int car=(a&b)<<1;
        a=a^b;
        swap(b,car);
       }
       return a;
    }
};