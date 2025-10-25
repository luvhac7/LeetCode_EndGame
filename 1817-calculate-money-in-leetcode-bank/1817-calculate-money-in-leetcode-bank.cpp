class Solution {
public:
    int totalMoney(int n) {
        int complete = n/7;
        int incomplete = n%7;
        int c1= (28*complete)+((complete*(complete-1))/2)*7;
        int c2= (incomplete*(incomplete+1))/2+(complete)*incomplete;
        return c1+c2;
    }
};