class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int n=a.size();
        if(a.size()<=2) return a.size();
        int j=2;
        for(int i=2;i<n;i++)
        {
            if(a[i]!=a[j-2])
            {
                a[j]=a[i];
                j++;
            }
        }
        return j;
    }
};