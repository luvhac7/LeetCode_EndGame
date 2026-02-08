class Solution {
public:
    int majorityElement(vector<int>& a) {

        int n=a.size();
        unordered_map<int,int>mp;
        for(int i:a) mp[i]++;
        for(auto i:mp){
        if(i.second>n/2) return i.first;
        }
        return -1;
    }
};