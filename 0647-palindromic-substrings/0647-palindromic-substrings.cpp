class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size(),count=0;

        for(int i=0;i<n;i++){
            // odd length
            for(int l=i,r=i;l>=0 && r<n && s[l]==s[r];l--,r++)
                count++;

            // even length
            for(int l=i,r=i+1;l>=0 && r<n && s[l]==s[r];l--,r++)
                count++;
        }
        return count;
    }
};