class Solution {
public:
    int longestSubsequence(vector<int>&a) {
        int n=a.size();
        int t=0,x=0;
        for(int i:a){
            x^=i;
            t+=(i!=0);
        }
        if(x!=0) return a.size();
        if(t) return a.size()-1;
        return 0;
    }
};