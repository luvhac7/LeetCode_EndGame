class Solution {
public:
    int minimumCost(vector<int>& a) {
        int m1=100,m2=100;
        for(int i=1;i<a.size();i++)
        {
            if(a[i]<m1)
            {
                m2=m1;
                m1=a[i];
            }
            else if(a[i]<m2)
            {
                m2=a[i];
            }
        }
        return a[0]+m1+m2;
    }
};