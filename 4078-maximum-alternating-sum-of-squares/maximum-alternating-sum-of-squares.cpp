class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        int k = (n % 2 == 0) ? n/2 : (n-1)/2;
        priority_queue<int> pq;
        long long sum = 0;
        for(int i : nums){
            pq.push(abs(i));
            while(pq.size() > k){
                pq.pop();
            }
            sum += 1LL*i*i;
        }

        while(!pq.empty()){
            int x = pq.top();
            pq.pop();
            sum -= 2LL*x*x;
        }

        return sum;
    }
};