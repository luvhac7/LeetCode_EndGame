class Solution {
public:
    int minOperations(vector<int>& a) {
        int n=a.size(),cnt=0;
        for(int i=0;i<n-2;i++)
        {
           // int x=2;
            if(a[i]==0)
            {
                a[i+1]^=1;
                a[i+2]^=1;
                cnt++;
            }
        }
        return a[n-1]==0 || a[n-2]==0 ? -1:cnt;
     }
};