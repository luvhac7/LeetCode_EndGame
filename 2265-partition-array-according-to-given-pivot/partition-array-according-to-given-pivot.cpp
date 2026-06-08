class Solution {
public:
    vector<int> pivotArray(vector<int>& a, int p) {
        vector<int>s,l,ans,b;
        for(int i=0;i<a.size();i++)
            if(a[i]<p)s.push_back(a[i]);
        for(int i=0;i<a.size();i++)
            if(a[i]==p) b.push_back(a[i]);
        for(int i=0;i<a.size();i++)
            if(a[i]>p) l.push_back(a[i]);
        for(int i:s)
            ans.push_back(i);
        for(int i:b)
            ans.push_back(i);
        for(int i:l)
            ans.push_back(i);
        return ans;
    }
};