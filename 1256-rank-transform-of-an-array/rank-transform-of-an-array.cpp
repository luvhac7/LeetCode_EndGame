class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
       int n=a.size();
        if(n==0) return {};
        set<int>uni(a.begin(),a.end());
        map<int,int>rank;
        int rnk=1;
        for(const int &it:uni)
        {
            rank[it]=rnk++;
        }
        vector<int>ans;
        for(int &it:a)
        {
            ans.push_back(rank[it]);
        }
        return ans;
    }
};