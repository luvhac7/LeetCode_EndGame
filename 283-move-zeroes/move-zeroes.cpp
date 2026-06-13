class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int cnt=0;
        for(int i:a) if(i==0) cnt++;vector<int>b=a;
        a.clear();
        for(int i=0;i<b.size();i++) if(b[i]!=0) a.push_back(b[i]);
        for(int i=0;i<cnt;i++) a.push_back(0);
    }
};