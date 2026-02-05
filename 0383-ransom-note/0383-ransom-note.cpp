class Solution {
public:
    bool canConstruct(string r, string m) {
// vector<int>f(26);
unordered_map<char,int>mp;
// for(int i=0;i<m.size();i++) f[m[i]-'a']++;
for(char c:m) mp[c]++;
for(char c:r) mp[c]--; 
// for(int i=0;i<r.size();i++){
//     f[r[i]-'a']--;
// }
    // for(int i=0;i<26;i++)
    // {
    //     if(f[i]<0) return false;
    // }
    for(auto &i:mp){
        if(i.second<0) return false;
    }
    return true;
    }
};