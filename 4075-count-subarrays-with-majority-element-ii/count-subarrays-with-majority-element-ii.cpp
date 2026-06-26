class Solution {
public:
typedef long long ll;
    long long countMajoritySubarrays(vector<int>& a, int tar) {
        ll c=0;int run=0;
        ll fq=0;
        map<int,int>f;
        f[0]=1;
        for(int i:a)
        {
            if(i==tar)
            {
                fq+=f[run];
                run++;
            }
            else{
                run--;
                fq-=f[run];
            }
            c+=fq;
            f[run]++;
        }
        return c;
    }
};