class Solution {
public:
int cnt=0;
    vector<int> searchRange(vector<int>& a, int t) {
        vector<int>ans;
        for(int i:a){
        if(i==t) ans.push_back(cnt);
        cnt++;
        }
       if(ans.empty()){ ans.push_back(-1);
        ans.push_back(-1);
       }
       int n=ans.size();
       return {ans[0],ans[n-1]};

    }
};