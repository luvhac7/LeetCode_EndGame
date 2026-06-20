class Solution {
public:
    int singleNumber(vector<int>& a) {
        map<int,int>f;for(int i:a)f[i]++;
        for(auto &it:f) if(it.second==1) return it.first;
        return a[0];
    }
};