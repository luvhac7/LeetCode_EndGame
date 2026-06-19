class Solution {
public:
    int largestAltitude(vector<int>& a) {
        int k=0,j=0;
        for(int i:a)
        {
            j+=i;
            k=max(k,j);
        }
        return k;
    }
};