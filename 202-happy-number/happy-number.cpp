class Solution {
public:
int tod(int n)
{
    int total=0;
    while(n>0)
    {
        int d=n%10;
        total+=d*d;
        n/=10;
    }
    return total;
}
    bool isHappy(int n) {
        set<int>st;
        while(n!=1 && st.find(n)==st.end())
            {
                st.insert(n);
                n=tod(n);
            }
        return n==1;
    }
};