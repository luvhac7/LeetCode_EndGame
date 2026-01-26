class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& a) {
    int n=a.size();
    int sz=n*n;
    vector<int>cnt(sz+1,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cnt[a[i][j]]++;
        }
    }
    int x=-1,y=-1;
    for(int i=1;i<=sz;i++)
    {
        if(cnt[i]==2)
        {
            x=i;
        }
        else if(cnt[i]==0)
        {
            y=i;
        }
    }
    return {x,y};
    }
};