class Solution {
public:
    string findDifferentBinaryString(vector<string>& a) {
        string x="";
        for(int i=0;i<a.size();i++)
        {
            if(a[i][i]=='1') x+='0';
            else x+='1';
        }
        return x;
    }
};