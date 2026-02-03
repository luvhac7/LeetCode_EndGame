class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        vector<int>x;
        for(int i:a)
        {
            if(x.empty()||x[x.size()-1]<i) x.push_back(i);
            else{
    auto it=lower_bound(x.begin(),x.end(),i);
    *it=i;
            }
        }
        return x.size();
    }
};