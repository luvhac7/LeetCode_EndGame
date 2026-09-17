class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = INT_MAX;
        vector<int> prefSum(n) , suffSum(n);
        prefSum[0] = arr[0];
        suffSum[n-1] = arr[n-1];
        for(int i = 1 ; i < n ; i++){
            prefSum[i] = prefSum[i-1] + arr[i];
        }
        for(int i = n-2 ; i >= 0; i--){
            suffSum[i] = suffSum[i+1] + arr[i];
        }

        map<int,int> mpp;
        mpp[0] = -1;

        vector<int> leftBest(n,0),rightBest(n,0);
        int left  = 1e9;
        int right = 1e9;
        for(int i = 0 ; i < n ; i++){
            int rem = prefSum[i] - target;
            if(mpp.find(rem) != mpp.end()){
                left = min(left , i - mpp[rem]);
            }
            leftBest[i] = left;
            mpp[prefSum[i]] = i;
        }

        map<int,int> mpp2;
        mpp2[0] = n;
        for(int i = n-1 ; i >= 0 ; i--){
            int rem = suffSum[i] - target;
            if(mpp2.find(rem) != mpp2.end()){
                right = min(right ,mpp2[rem] - i);
            }
            rightBest[i] = right;
            mpp2[suffSum[i]] = i;
        }

        for(int i = 0 ; i < n - 1; i++){
            int leftSubarr  = leftBest[i];
            int rightSubarr = rightBest[i+1];
            if(leftSubarr == 1e9 || rightSubarr == 1e9) continue;

            ans = min( ans , leftSubarr + rightSubarr);
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};