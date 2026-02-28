class Solution {
public:

void f(vector<int>&a,int &i,int &j,int cnt)
{
    int k=0,val=a[j];
    while(j<a.size()&&a[j]==val&&k<cnt)
    {
        a[i]=val;i++;j++;k++;
    }
}
    int removeDuplicates(vector<int>& a) {
        int i=0,sz=a.size();
        for(int j=0;j<a.size();)
        {
            f(a,i,j,2);
            while(j<a.size()&&a[j]==a[j-1]) j++;
        }
        return i;
        
    }
};