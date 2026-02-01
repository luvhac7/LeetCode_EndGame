class Solution {
public:
vector<string>b20={"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
vector<string>ten={"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
string f(int n)
{
    if(n==0) return "";
    if(n<20) return b20[n]+" ";
    if(n<100) return ten[n/10]+" "+f(n%10);
    return b20[n/100]+" Hundred "+f(n%100);
}
    string numberToWords(int n) {
        if(n==0) return "Zero";
        string ans="";
        int b=n/1e9;
        int m=(n/1000000)%1000;
        int t=(n/1000)%1000;
        int r=n%1000;

       if(b)ans+=f(b)+"Billion ";
       if(m)ans+=f(m)+"Million ";
       if(t)ans+=f(t)+"Thousand ";
       if(r)ans+=f(r);

       while(!ans.empty()&&ans.back()==' ') ans.pop_back();
       return ans;
    }
};