class Solution {
public:
    int uniqueXorTriplets(vector<int>& a) {
        int n=a.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                st.insert(a[i]^a[j]);
            }
        }
        unordered_set<int>res;
        for(auto i:st)
        {
            for(auto j:a)
            {
                res.insert(i^j);
            }
        }
        return res.size();
    }
};