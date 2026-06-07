class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        // auto *lb=lower_bound(a.begin(),a.end(),a[a.size()-1]);
        // cout<<lb<<" ";
        // return a[0];
        int n=a.size();
        int i=0,j=1;
    for(int i=0;i<n;i++)
            {
                if(a[i]!=a[j-1]){
                    a[j]=a[i];
                    j++;
                }
                  //  i++;
            }
            return j;
    }
};