class Solution {
public:
typedef unsigned long long ll;
    int change(int n, vector<int>& c) {
        if (n == 0)
            return 1;

        vector<ll> dp(n + 1, 0);
        //dp ko n+1 size ka bna diya aur dp[n+1]->(0,0,0,0...ntimes+1)
        //starting ya fir agar kuch nhi toh dp[0] hoga means alteast one toh 
        //hoga hi
        //means it will be the base val when the amount > cost in arr

        dp[0] = 1;
        for (int i : c) {
            //(1,2,3,4)
            //(0,1,2,3)
            //0 wale to continue

            if (i <= 0)
                continue;
            //j->1 se j->n tak 
            //dp[1]+=dp[1-1]+=dp[0]
            //dp[2]+=dp[2-1]+=d[1]
            //dp[3]+=dp[3-1]+=d[2]
            //dp[4]+=d[4-1]+=d[3]
            for (int j = i; j <= n; j++) {
                dp[j] += dp[j-i];
            }
        }
        return (int)dp[n];
    }
};
