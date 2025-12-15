class Solution {
public:
typedef long long ll;
    long long getDescentPeriods(vector<int>& pr) {
        ll ans=1;
        ll len=1;
        for(int i=1;i<pr.size();i++)
        {
            if(pr[i]==pr[i-1]-1){
                len++;
            }
            else{
                len=1;
            }
            ans+=len;
        }
        return ans;
    }
};