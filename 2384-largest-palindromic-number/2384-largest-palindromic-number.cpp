class Solution {
public:
    string largestPalindromic(string num) {
        vector<int>f(10);
        for(char c:num){
            f[c-'0']++;
        }
        string l,r;
        for(int i:num){
            for(int j=9;j>=0;j--){
        if(f[j]>1 && (j>0 || l.size())){
            l+='0'+j;
            r+='0'+j;
            f[j]-=2;
            break;
        }
            }
        }
        for(int i=9;i>=0;i--){
            if(f[i]){
                l+='0'+i;break;
            }
        }
        reverse(begin(r),end(r));
        return l+r;
    }
};