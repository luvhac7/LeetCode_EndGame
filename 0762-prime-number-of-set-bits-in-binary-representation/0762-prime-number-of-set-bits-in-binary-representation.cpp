class Solution {
public:
vector<int>b={2,3,5,7,11,13,17,19};
const int mask = 665772;
int optimized(int l,int r)
{
    int cnt=0;
    for(int i=l;i<=r;i++)
    {
        cnt+=(mask>>__builtin_popcount(i)) & 1;;
    }
    return cnt;
}
    int countPrimeSetBits(int l, int r) {
        // int cnt = 0;
        // for(int i = l; i <= r; i++) {
        //     int bit=__builtin_popcount(i);
        //    for(int j=0;j<b.size();j++)
        //    {
        //     if(bit==b[j])
        //     {
        //         cnt++;
        //         break;
        //     }
        //    }
        // }
        // return cnt;
        return optimized(l,r);
    }
};