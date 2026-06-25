class Solution {
public:
typedef vector<vector<int>> vii;
static const int M=1e6;
vector<bool>prime;
Solution():prime(M+1,true){
    sieve();
}
void sieve()
{
    prime[0]=prime[1]=false;
    for(int i=2;i*i<=M;i++)
    {
        if(prime[i])
        {
            for(int j=i*i;j<=M;j+=i)
            {
                prime[j]=false;
            }
        }
    }
}
    vector<vector<int>> findPrimePairs(int n) {
        vii ans;
        for(int i=2;i<=n/2;i++)
        {
            if(prime[i] && prime[n-i])
            {
                ans.push_back({i,n-i});
            }
        }
        return ans;
    }
};