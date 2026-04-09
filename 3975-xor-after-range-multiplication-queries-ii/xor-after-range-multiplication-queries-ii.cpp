class Solution {
    long long modInverse(long long a,long long MOD){
        return modPower(a,MOD-2,MOD);
    }
    long long modPower(long long x, long long y, long long P){    
        if( y == 0LL) return 1LL;
        long long tmp = modPower(x, y/2LL, P);
    
        if(y&1) return (((x*tmp)%P)*tmp)%P ;
        else return  ((tmp*tmp)%P) ;
    }
    int getOrDefault(map<pair<int,int>,int>& mp, pair<int,int> key, int defaultVal) {
        auto it = mp.find(key);
        if(it == mp.end()) return defaultVal;
        return it->second;
    }
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int S = sqrt(n) + 1; 
        vector<map<pair<int,int>,int>> events(S);
        int MOD = 1e9 + 7;
        for(auto& q: queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if(k >= S) {
                for(int i=l; i<=r; i+=k) {
                    nums[i] = (1LL * nums[i] * v) % MOD;
                }
                continue;
            }
            // for smaller k
            events[k][{l%k,l}] = (1LL * getOrDefault(events[k], {l%k,l}, 1) * v) % MOD;
            int r2 = r + (k - (r - l)%k);
            if(r2 < n) {
                events[k][{r2%k,r2}] = (1LL* getOrDefault(events[k], {r2%k,r2}, 1) * modInverse(v, MOD)) % MOD;
            }
        }
        for(int k=1; k<S; k++){
            map<pair<int,int>,int>& e = events[k];
            auto it = e.begin();
            while(it != e.end()) {
                int start = (it)->first.second;
                int multBy = 1;
                int x = start % k;
                for(int i=start; i<n; i+=k) {
                    if(it->first.second == i) {
                        multBy = (1LL * multBy * it->second) % MOD;
                        ++it;
                    }
                    nums[i] = (1LL * nums[i] * multBy) % MOD;
                }
            }
        }
        int res = 0;
        for(int x : nums) res ^= x;
        return res;
    }
};