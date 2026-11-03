class Solution {
public:
    int minMoves(vector<int>& a) {
        int mx=0,s=0;
        for(int i:a){
            mx=max(mx,i);
            s+=i;
        }
        return a.size()*mx-s;
    }
};