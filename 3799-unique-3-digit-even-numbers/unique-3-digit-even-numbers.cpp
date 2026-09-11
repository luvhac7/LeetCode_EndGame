class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int count = 0;
        vector <int> freq (10, 0);
        for(int num : digits){
            freq[num]++;
        } 

        for(int i = 100; i <= 998; i += 2){
            int a = i / 100;
            int b = (i / 10) % 10;
            int c = i % 10;

            vector<int> temp = freq;

            temp[a]--;
            temp[b]--;
            temp[c]--;

            if(temp[a] >= 0 && temp[b] >= 0 && temp[c] >= 0){
                count++;
            }
        }
        return count;
    }
};