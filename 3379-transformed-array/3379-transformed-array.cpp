class Solution {
public:
    vector<int> constructTransformedArray(vector<int>&a) {int n=a.size();
        vector<int>res(n);for(int i=0;i<n;i++)res[i]=a[(i+(a[i])%n+n)%n];
        return res;
    }
};