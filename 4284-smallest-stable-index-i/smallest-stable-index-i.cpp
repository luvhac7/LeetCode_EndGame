class Solution {
public:
    int firstStableIndex(vector<int>& a, int k) {
        int n=a.size();
        vector<int>mini(n);
        mini[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            mini[i]=min(a[i],mini[i+1]);
        }
        int maxi=a[0];
        for(int i=0;i<n;i++){
            maxi=max(maxi,a[i]);
            if(maxi-mini[i]<=k) return i;
        }
    
    return -1;
}
};