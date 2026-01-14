class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        sort(a.begin(),a.end(),[](auto &x,auto &y){return x[1]<y[1];});
        int p=a[0][1],cnt=0;
        for(int i=1;i<a.size();i++)
        {
            if(p>a[i][0]) cnt++;
            else{
                p=a[i][1];
            }
        }
        return cnt;

    }
};