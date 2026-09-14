class Solution {
public:
    vector<int> recoverOrder(vector<int>& a, vector<int>& b) {
        set<int>st(b.begin(),b.end());
        vector<int>res;
        for(int i:a){
            if(st.count(i)) res.push_back(i);
        }
        return res;
    }
};