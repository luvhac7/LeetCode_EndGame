class Solution {
public:
typedef long long ll;
ll x=0,cnt=0;
    int findMaxConsecutiveOnes(vector<int>& a) {
        for(ll i:a)
        {
            if(i==1)
            {
                cnt++;
                x=max(cnt,x);
            }
          else{
            cnt=0;
          }
        }
    return x;
    }
};