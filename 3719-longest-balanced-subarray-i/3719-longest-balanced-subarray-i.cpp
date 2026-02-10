class Solution {
public:
    int longestBalanced(vector<int>& a) {
        int n=a.size(),maxi=0;
        for(int i=0;i<a.size();i++)
        {
            unordered_set<int>o,e;
            for(int j=i;j<a.size();j++)
            {
                if(a[j]&1) o.insert(a[j]);
                else e.insert(a[j]);
                if(o.size()==e.size()) maxi=max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};