class Solution {
public:
    string mapWordWeights(vector<string>& w, vector<int>& wt) {
        string x="";
        for(string s:w)

        {
            int sum=0;
            for(char i:s)
            {
                sum+=wt[i-'a'];
            }
            x+='z'-(sum%26);
        }
        return x;
    }
};