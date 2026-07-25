class Solution {
public:
    int maxProduct(int n) {
        vector<int>d;
        while(n>0)
        {
            d.push_back(n%10);n/=10;
        }
        sort(d.begin(),d.end());
        int x=d.size();
        return d[x-1]*d[x-2];
    }
};