class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& a) {
        if(!a.size()) return 0;
        sort(a.begin(),a.end(),[](auto &x,auto &y){
            return x[1]<y[1];
        });
        int p=a[0][1];
        int cnt=0;
        for(int i=1;i<a.size();i++)
        {
            if(a[i][0]>p)
            {
                cnt++;
                p=a[i][1];
            }
        }
        return cnt+1;
    }
};