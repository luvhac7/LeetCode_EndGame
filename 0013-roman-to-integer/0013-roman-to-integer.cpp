class Solution {
public:
    int romanToInt(string s) {
     int ans=0;
     unordered_map<char,int>f{
        {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
     };
     for(int i=0;i<s.size();i++)
     {
        if(f[s[i]]<f[s[i+1]])
        {
            ans=ans-f[s[i]];
        }
        else{
            ans=ans+f[s[i]];
        }
     }   
     return ans;
    }
};