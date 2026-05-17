class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start]==-1) return false;
        if(!arr[start]) return true;
        int left=start-arr[start];
        int right=start+arr[start];
        arr[start]=-1;
        return right=(right &&right<arr.size()&&canReach(arr,right))||(left>=0 && canReach(arr,left));
    }
};