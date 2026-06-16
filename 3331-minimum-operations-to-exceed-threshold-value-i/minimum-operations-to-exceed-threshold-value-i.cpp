class Solution {
public:
int x=0;
    int minOperations(vector<int>& a, int k) {
        for(int i:a) if(i<k )x++;
        return x;
    }
};