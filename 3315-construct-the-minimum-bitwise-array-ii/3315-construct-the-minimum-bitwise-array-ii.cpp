class Solution {
public:
vector<int>res;
    vector<int> minBitwiseArray(vector<int>& a) {
        for(int i:a){
            if(i!=2){
                res.push_back(i-((i+1)&(-i-1))/2);
            }
            else res.push_back(-1);
        }
        return res;
    }
};