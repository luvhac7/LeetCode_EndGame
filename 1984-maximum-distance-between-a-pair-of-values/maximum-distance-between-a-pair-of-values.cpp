class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int x=a.size(),y=b.size(),i=0,j=0,res=INT_MIN;
        while(i<x && j<y)
        {
            if(a[i]<=b[j])
            {
                res=max(res,j-i);
                j++;
            }
            else{
                i++;
            }
        }
        return res==INT_MIN || res<0? 0:res;
    }
};