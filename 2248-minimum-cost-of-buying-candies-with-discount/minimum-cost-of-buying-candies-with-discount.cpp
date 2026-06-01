class Solution {
public:
    int minimumCost(vector<int>& a) {
        sort(a.begin(),a.end());int t=0;
        for(int i=a.size()-1;i>=0;i-=3){
            t+=a[i];
            if(i-1>=0) t+=a[i-1];
        }
    return t;
    }
};