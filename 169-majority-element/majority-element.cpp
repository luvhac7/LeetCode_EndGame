class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n=a.size();
        // for(int i=n-1;i>=0;i--)
        // {
        //     if()
        // }
        map<int,int>f;for(int i:a) f[i]++;
        for(auto &i:f){
            if(i.second>n/2) return i.first;
        }
        return a[0];
    }
};