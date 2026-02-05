class Solution {
public:
    bool canConstruct(string r, string m) {
        // if(r==m) return true;
        // sort(r.begin(),r.end());sort(m.begin(),m.end());
        // int n=min(r.size(),m.size());
        // // for(int i=0;i<n;i++)
        // // {
        // //     // if(s.substr())
        // // }
vector<int>f(26);
for(int i=0;i<m.size();i++) f[m[i]-'a']++;
for(int i=0;i<r.size();i++){
    f[r[i]-'a']--;
}
    for(int i=0;i<26;i++)
    {
        if(f[i]<0) return false;
    }
    return true;
    }
};