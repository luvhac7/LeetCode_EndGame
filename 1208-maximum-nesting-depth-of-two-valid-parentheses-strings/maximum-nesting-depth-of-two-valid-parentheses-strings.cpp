class Solution {
public:
    vector<int> maxDepthAfterSplit(string a) {
        int n=a.size();
        vector<int>res(n);
        for(int i=0;i<n;i++) res[i]=(i^a[i])&1;
        return res;
        }
};