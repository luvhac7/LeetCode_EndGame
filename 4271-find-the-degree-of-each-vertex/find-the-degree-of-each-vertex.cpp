class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& a) {
        vector<int>x;
        for(int i=0;i<a.size();i++)
        {
            int s=0;
            for(int j=0;j<a.size();j++)
            {
                s+=a[i][j];
            }
            x.push_back(s);
        }
return x;
    }
};