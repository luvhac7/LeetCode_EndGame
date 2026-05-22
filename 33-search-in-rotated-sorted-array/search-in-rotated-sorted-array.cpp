class Solution {
public:
    int search(vector<int>& a, int x) {
        for(int i=0;i<a.size();i++) if(a[i]==x) return i;
        return -1;
    }
};