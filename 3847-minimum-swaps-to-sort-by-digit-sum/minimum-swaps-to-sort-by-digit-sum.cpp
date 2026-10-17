class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int size = nums.size();
        unordered_map<int, int>map;
        
        for(int i=0;i<size;i++){
            int temp = nums[i];
            int digitSum = 0;
            while(temp > 0){
                int digit = temp%10;
                digitSum += digit;
                temp /=10;
            }
            map[nums[i]] = digitSum;
        }

        vector<int>tempVec(nums.begin(), nums.end());
        sort(tempVec.begin(), tempVec.end(), [&] (int a, int b) {
            if(map[a] != map[b]) return map[a] < map[b];
            return a < b;
        });

        unordered_map<int, int>pos;
        for(int i=0;i<size;i++){
            pos[nums[i]] = i;
        }

        int swaps = 0;
        for(int i=0;i<size;i++){
            if(tempVec[i] != nums[i]){
                int index = pos[tempVec[i]];
                swap(nums[i], nums[index]);

                pos[nums[i]] = i;
                pos[nums[index]] = index;

                swaps++;
            }
        }
        return swaps;
    }
};