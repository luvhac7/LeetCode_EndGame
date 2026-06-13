class Solution {
public:
    int search(vector<int>& a, int t) {
        int high=a.size()-1,low=0;
        if(a[0]==t) return 0;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(a[mid]==t){ return mid;}
            else if(a[mid]<t){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return -1;
    }
};