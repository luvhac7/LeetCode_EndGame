class Solution {
public:
typedef long long l;
    bool asteroidsDestroyed(int ma, vector<int>& a) {
        sort(a.begin(),a.end());l m=ma;
        for(int i=0;i<a.size();i++)
        {
            if(m<a[i]) return false;
            m+=a[i];
        }
        return true;
    }
};