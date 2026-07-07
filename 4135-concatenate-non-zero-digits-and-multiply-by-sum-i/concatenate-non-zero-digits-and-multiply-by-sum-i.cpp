class Solution {
public:
typedef long long ll;
    long long sumAndMultiply(int n) {
        vector<int>d;ll no=n,s=0,p=0;
        while(n>0)
        {
        if(n%10 != 0){
            d.push_back(n%10);
        }
        n/=10;
        }
        if(d.empty()) return 0;
        for(int i:d)
        {
            p+=i;
        }
        string res="";
        for(int i:d)
        {
            res+=to_string(i);
            cout<<res<<" ";
        }
        reverse(res.begin(),res.end());
    return (ll)p*std::stoll(res);
    }
};