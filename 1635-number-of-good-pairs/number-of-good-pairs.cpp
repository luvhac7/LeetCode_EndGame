class Solution {
public:
    int numIdenticalPairs(vector<int>& a) {
        map<int,int>f;
        for(int i:a) f[i]++;
        int cnt=0;
        for(auto it:f){
            if(it.second>1){
                int x=it.second;
                cnt+=x*(x-1)/2;
            }
        }
        return cnt;
    }
};