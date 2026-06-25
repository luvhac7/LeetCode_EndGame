class Solution {
public:
typedef vector<int> vi;
bool f(int n)
{
    if(n<2) return false;
    for(int i=2;i*i<=n;i++) if(n%i==0) return false;
    return true; 
}
    vector<int> closestPrimes(int l, int r) {
        vi ans;//ans.push_back(-1);
        // ans.push_back(-1);
        for(int i=l;i<=r;i++)
        {
            if(f(i))
            {
                ans.push_back(i);
            }
        }

       if(ans.size() < 2) return {-1, -1};

        int mn = INT_MAX;
        vi res;

        for(int i = 1; i < ans.size(); i++) {
            if(ans[i] - ans[i - 1] < mn) {
                mn = ans[i] - ans[i - 1];
                res = {ans[i - 1], ans[i]};
            }
        }

        return res;
    }
};