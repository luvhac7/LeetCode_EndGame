class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),[](auto &x,auto &y){return x[0]==y[0]? x[1]>y[1]:x[0]<y[0];});
        int cnt=0,ans=0;
        for(auto &i:a){
            if(i[1]>ans){
                cnt++;
                ans=i[1];
            }
        }
        return cnt;
    }
};