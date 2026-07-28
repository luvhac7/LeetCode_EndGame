class Solution {
public:
  string f(string s){
        vector<int>f(26,0);
        for(char c:s) f[c-'a']++;
        int n=s.size();
        string ans(n,' ');
        int l=0,r=n-1;
        for(int i=0;i<26;i++){
            while(f[i]>=2){
                ans[l++]=char('a'+i);
                ans[r--]=char('a'+i);
                f[i]-=2;
            }
            if(f[i]==1) ans[s.size()/2]=char('a'+i);
    }
    return ans;
}
    string smallestPalindrome(string s) {
        return f(s);
    }
};