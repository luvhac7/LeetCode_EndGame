class Solution {
public:
typedef long long ll;
    int maximumLength(vector<int>& a) {
        map<int,int>f;for(int i:a) f[i]++;
        int ans=1; if(f.count(1)) { int c= f[1]; ans=(c%2!=0) ? c:c-1;}
        for(auto &[i,cnt]:f)
        {
            if(i==1) continue;
            int cur=0;
            ll x=i;
            while(f.count(x) && f[x]>=2)
            {
                cur+=2;
                if(x>1e9/x){x=x*x;break;}
                x=x*x;
            }
            if(f.count(x) && f[x]>=1)
            {
                cur+=1;
            }
            else{
                cur-=1;
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};