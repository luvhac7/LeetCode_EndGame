class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        int k=reduce(a.begin(),a.end())-x,n=a.size();
        if(k<0) return -1;
        if(k==1) return n;
        int best=-1,i=0,sum=0;
        for(int j=0;j<n;j++){
            sum+=a[j];
            while(sum>k) sum-=a[i++];
            if(sum==k) best=max(best,j-i+1);
        }
        return best+1? n-best :-1;
    }
};