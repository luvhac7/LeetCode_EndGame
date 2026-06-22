class Solution {
public:
    int maxNumberOfBalloons(string a) {
        map<char,int>f;for(char c:a)f[c]++;
        string t="ballon";
        int maxi=100000000000;
        for(char c:t)
        {
            int cnt=f[c];
            if(c=='l'||c=='o') cnt/=2;
            maxi=min(maxi,cnt);
        }
        return maxi;
    }
};