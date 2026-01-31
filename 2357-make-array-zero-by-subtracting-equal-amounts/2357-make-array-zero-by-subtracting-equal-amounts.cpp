class Solution {
public:
    int minimumOperations(vector<int>& a) {
        int k=0,p=0;
        sort(a.begin(),a.end());
        //if(a.size()==1) return a[0];
        for(int i=0;i<a.size();i++)
        {
            if(a[i]>p)
            {
            int d=a[i]-p;
                k++;p=a[i];
            }
        }
        return k;
    }
};