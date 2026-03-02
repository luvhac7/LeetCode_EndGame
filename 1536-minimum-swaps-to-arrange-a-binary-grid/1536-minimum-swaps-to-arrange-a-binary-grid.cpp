class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        vector<int>tz;
        for(auto v : grid){
            int cnt = 0;
            for(int j = v.size()-1;j>=0 && v[j] == 0;j--) cnt++;
            tz.push_back(cnt);
        }

        for(int i=0;i<n;i++){
            int need = n - i -1;
            int j = i;
            while(j < n && tz[j] < need) j++;

            if(j == n) return -1;

            while(j > i){
                ans++;
                swap(tz[j],tz[j-1]);
                j--;
            }
        }
        return ans;
    }
};