class Solution {
public:
    int smallestIndex(vector<int>& a) {
        for(int o=0;o<a.size();o++){
            int x=a[o],s=0;
            while(x>0){
                s+=x%10;x/=10;
            }
            if(s==o) return o;
        }
        return -1;
    }
};