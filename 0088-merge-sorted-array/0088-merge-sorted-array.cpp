class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        //i=m-1,j=n-1,k=m+n-1;
        int i=m-1,j=n-1,k=m+n-1;//end->i,j,
        //i>=0 j>=0
        while(i>=0 && j>=0)
        {
            //a
            if(a[i]>b[j]){
                //k->ans
                a[k]=a[i];i--;k--;
            }
           else{
                a[k]=b[j];k--;j--;
            }
             
        }
        while(j>=0)
        {
            a[k]=b[j];j--;k--;
        }
        
        
    }
};