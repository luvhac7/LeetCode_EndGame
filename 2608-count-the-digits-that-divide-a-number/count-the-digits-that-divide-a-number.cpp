class Solution {
public:
int g=0;
    int countDigits(int n) {
        vector<int>d;
        int res=n;
        while(n>0)
        {
            d.push_back(n%10);n/=10;
        }
        for(int i:d) cout<<i<<" ";
        for(int i=0;i<d.size();i++)
        {   
            if(res%d[i]==0) g++;
        }
    return g;
    }

};