class Solution {
public:
    string largestNumber(vector<int>& a) {
        vector<string>x;
        for(int i:a)

{
    x.push_back(to_string(i));

}    
sort(x.begin(),x.end(),[](string &a,string &b){return a+b>b+a;});
if(x[0]=="0") return "0";
string y="";
for(string &i:x) y+=i;
return y;
}
};