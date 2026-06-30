class Solution {
public:
    int digitFrequencyScore(int n) {
        map<int,int>f;int x=0;
        vector<int>d;int no=n;while(n>0){d.push_back(n%10);n/=10;}
        for(int i:d)f[i]++;
        for(auto &i:f){x+=i.first*i.second;}
        return x;
    }
};