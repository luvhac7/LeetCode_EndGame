class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),[](auto &x,auto &y){return x[1]<y[1];});
        int cnt=0,prev=a[0][1];
        for(int i=1;i<a.size();i++)
        {
            if(a[i][0]<prev) cnt++;
            else{
                prev=a[i][1];
            }
        }
        return cnt;
        
    }
};