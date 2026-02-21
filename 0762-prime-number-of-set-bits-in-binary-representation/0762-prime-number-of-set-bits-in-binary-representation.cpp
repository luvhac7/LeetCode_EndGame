class Solution {
public:
vector<int>b={2,3,5,7,11,13,17,19};
    int countPrimeSetBits(int l, int r) {
        int cnt = 0;
        for(int i = l; i <= r; i++) {
            int bit=__builtin_popcount(i);
           for(int j=0;j<b.size();j++)
           {
            if(bit==b[j])
            {
                cnt++;
                break;
            }
           }
        }
        return cnt;
    }
};