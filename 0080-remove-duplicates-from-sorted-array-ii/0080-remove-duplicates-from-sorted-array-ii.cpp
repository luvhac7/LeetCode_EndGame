class Solution {
public:

int un(vector<int>&a)
{
unordered_map<int,int>f;
int k=0;
for(int i:a)
{
    f[i]++;
    if(f[i]<=2)
    {
        a[k]=i;
        k++;
    }
}
return k;
}
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
        // for(int j=0;j<a.size();)
        // {
        //     f(a,i,j,2);
        //     cout<<a[i]<<" "<<a[j]<<" "<<"\n"; 
        //     while(j<a.size()&&a[j]==a[j-1]) j++;
        // }
    return un(a);
        
    }
};