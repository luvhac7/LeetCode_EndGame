class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& s, int t) {
        vector<int>ans;
        if(t==0){
            for(int i=0;i<s.size();i++){ ans.push_back(i);} return ans;
        }
        int n=s.size();
    vector<int>pre(n),suf(n);
    for(int i=1;i<n;i++)
    {
        if(s[i]<=s[i-1]){
            pre[i]=pre[i-1]+1;
        }
    }
    for(int i=n-2;i>=0;i--)
    {
        if(s[i]<=s[i+1]){
            suf[i]=suf[i+1]+1;
        }
    }
    for(int i=t;i<n-t;i++)
    {
        if(pre[i]>=t && suf[i]>=t){
            ans.push_back(i);
        }
    }
    return ans;


    }
};