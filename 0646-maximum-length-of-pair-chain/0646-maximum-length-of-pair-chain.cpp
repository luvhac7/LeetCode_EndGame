class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        sort(p.begin(),p.end(),
        [](auto &a,auto &b){
            return a[1]<b[1];
        }
        );
        int last=p[0][1];
        int cnt=1;
        for(int i=1;i<p.size();i++){
            if(p[i][0]>last)
            {
                cnt++;
                last=p[i][1];
            }
        }
        return cnt;
    }
};