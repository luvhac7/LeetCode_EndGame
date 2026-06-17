class Solution {
public:
    int singleNumber(vector<int>& a) {
        map<int,int>f;for(int i:a) f[i]++;
        for(auto &i:f){
            if(i.second==1) return i.first;
        }
        return -1;
    }
};