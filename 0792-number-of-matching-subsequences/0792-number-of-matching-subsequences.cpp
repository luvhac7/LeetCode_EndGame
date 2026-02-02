class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& w) {
    int n=s.size();
    vector<vector<int>>f(26);
    for(int i=0;i<n;i++) f[s[i]-'a'].push_back(i);
        int ans=w.size();
    for(auto &i:w)
    {
    int lst=-1;
    for(char c:i)
    {
        auto &idx=f[c-'a'];
    auto it=upper_bound(idx.begin(),idx.end(),lst);
if(it==idx.end()){
    ans--;
    break;
}
else{
    lst=*it;
}
    }
    }
    
    return ans;
    }
};