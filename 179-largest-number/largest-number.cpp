class Solution {
static bool cmp(string a,string b)
{
    return a+b>b+a;
}
public:
    string largestNumber(vector<int>& a) {
        vector<string>v;int z=0;
        for(int i:a)
        {
            if(i==0)z++;
            v.push_back(to_string(i));
        }if(z==a.size()) return "0";
        string ans="";
        sort(v.begin(),v.end(),cmp);
        for(string i:v){
            ans+=i;
        }
        return ans;
}
};