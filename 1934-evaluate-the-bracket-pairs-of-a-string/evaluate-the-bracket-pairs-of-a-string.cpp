class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> mp;
        string ans = "";
        for(auto it:knowledge)
            mp[it[0]]=it[1];
        for(int i=0;i<s.size();i++){
            if(s[i]!='('){
                ans+=s[i];
            }
            else {
                int j = i+1;
                string tmp="";
                while(j<s.size() && s[j]!=')'){
                    tmp+=s[j];
                    j++;
                }
                i=j;
                if(mp.find(tmp)!=mp.end())
                    ans+=mp[tmp];
                else 
                    ans+='?';
            }
        }
        return ans;
    }
};