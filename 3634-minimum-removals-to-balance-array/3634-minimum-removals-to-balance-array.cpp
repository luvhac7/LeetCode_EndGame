class Solution {
public:
    int minRemoval(vector<int>& a, int k) {
        int x=0;sort(a.begin(),a.end());
        for(int i:a)
        {
            x+=i>1L*a[x]*k;
        }
        return x;
    }
};