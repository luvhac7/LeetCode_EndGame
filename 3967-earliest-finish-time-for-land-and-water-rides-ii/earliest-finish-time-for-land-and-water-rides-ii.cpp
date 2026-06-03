class Solution {
public:
    int earliestFinishTime(vector<int>& lst, vector<int>& ld, vector<int>& wst, vector<int>& wd) {
    int n=lst.size(),m=wst.size();
    int minl=1e6,minw=1e6;
    for(int i=0;i<n;i++) minl=min(minl,lst[i]+ld[i]);
    int ans=1e9;
    for(int i=0;i<m;i++){
        minw=min(minw,wst[i]+wd[i]);
        ans=min(ans,max(minl,wst[i])+wd[i]);
    }
for(int i=0;i<n;i++) ans=min(ans,max(minw,lst[i])+ld[i]);

    return ans;
        
    }
};