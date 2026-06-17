class Solution {
public:
    int missingNumber(vector<int>& a) {
        // int n=a.size();sort(a.begin(),a.end());
        // for(int i=0;i<a[n-1];i++)
        //     if(a[i]!=i) return i;
        // return a[n-1]+1;
        int s=0,n=a.size();
        int ex=n*(n+1)/2;
        for(int i:a)
        {
            s+=i;
        }
        return ex-s;
    }
};