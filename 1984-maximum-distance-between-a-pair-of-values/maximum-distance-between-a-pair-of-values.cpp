class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int i=0,j=0;
        int maxi=0;
        int n1=a.size();
        int n2=b.size();
        while(i<n1&&j<n2)
        {
            if(a[i]<=b[j])
            {
                maxi=max(maxi,j-i);
                j++;
            }
            else{
                i++;
            }
        }
    return maxi;
    } 
};