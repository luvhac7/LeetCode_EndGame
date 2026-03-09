class Solution {
public:
    int mod = 1e9+7;
    int backtrack(int limit, int lastCount, int oneCount, int zeroCount, int last,
    int dp[][201][201][201]){
        cout<<last<<" ";
        if(zeroCount<0 || oneCount<0 || lastCount>limit) {
            // cout<<endl;
            return 0;
            }
        if(oneCount==0 && zeroCount==0) {
            
            return 1;
            
            }

        if(last!=-1)
        if(dp[last][lastCount][oneCount][zeroCount]!=-1) return dp[last][lastCount][oneCount][zeroCount];

        int total = 0;
        if(last==1){
            total = (total + backtrack(limit, lastCount+1, oneCount-1, zeroCount, last, dp))%mod;
        }
        else{
            total  = (total + backtrack(limit, 1, oneCount-1, zeroCount, 1, dp))%mod;
        }
        if(last==0){
            total = (total + backtrack(limit, lastCount+1, oneCount, zeroCount-1, last, dp))%mod;
        }
        else{
            total  = (total + backtrack( limit, 1, oneCount, zeroCount-1, 0, dp))%mod;
        }

        return dp[last][lastCount][oneCount][zeroCount] = total;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        int dp[2][201][201][201];
        memset(dp,0, sizeof(dp));
        
            for(int oneCount=0; oneCount<=one; oneCount++){
                for(int zeroCount=0; zeroCount<=zero; zeroCount++){
                    for(int lastCount = limit ; lastCount>0; lastCount--){
                    for(int last = 0; last<=1; last++){
                        if(oneCount==0 && zeroCount==0){
                            dp[last][lastCount][oneCount][zeroCount]=1;
                            continue;
                        }
                        int total = 0;
                        if(last==1){
                            if(oneCount!=0 && lastCount <limit)
                            total = (total + dp[1][lastCount+1][oneCount-1][zeroCount])%mod;
                        }
                        else{
                            if(oneCount!=0)
                            total = (total + dp[1][1][oneCount-1][zeroCount])%mod;
                        }
                        if(last==0){
                            if(zeroCount!=0&& lastCount <limit)
                            total = (total + dp[0][lastCount+1][oneCount][zeroCount-1])%mod;
                            
                        }
                        else{
                            if(zeroCount!=0)
                            total = (total + dp[0][1][oneCount][zeroCount-1])%mod;
                        }

                        dp[last][lastCount][oneCount][zeroCount]=total;
                    }
                }
            }
        }
        int answer = (dp[0][1][one][zero-1] + dp[1][1][one-1][zero])%mod;

        return answer;
        // return (backtrack(limit, 1, one, zero-1, 0, dp) + backtrack(limit, 1, one-1, zero, 1, dp))%mod;
    }
};