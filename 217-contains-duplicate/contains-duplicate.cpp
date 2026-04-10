class Solution {
public:
    bool containsDuplicate(vector<int>& a){
        set<int>st;
        for(int i:a) st.insert(i);
        return st.size()!=a.size();
    }
};