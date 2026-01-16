class Solution {
public:
    int centeredSubarrays(vector<int>& a) {
        int x=0;
        for(int i=0;i<a.size();i++)
        {
            int y=0;
            unordered_set<int>st;
            for(int j=i;j<a.size();j++)
            {
                y+=a[j];
                st.insert(a[j]);
                x+=st.count(y)==true ? 1:0;
            }
        }
        return x;
    }
};