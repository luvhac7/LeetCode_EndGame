class Solution {
public:
    int centeredSubarrays(vector<int>& a) {
        int ans=0;
        for(int i=0;i<a.size();i++)
        {
            int sum=0;
            unordered_set<int>st;
            for(int j=i;j<a.size();j++)
            {
                sum+=a[j];
                st.insert(a[j]);
                ans+=st.count(sum)==true ? 1:0;
            }
        }
        return ans;
    }
};