class Solution {
public:
    int missingNumber(vector<int>& a) {
        int n=a.size();sort(a.begin(),a.end());
        for(int i=0;i<a[n-1];i++)
            if(a[i]!=i) return i;
        return a[n-1]+1;
    }
};