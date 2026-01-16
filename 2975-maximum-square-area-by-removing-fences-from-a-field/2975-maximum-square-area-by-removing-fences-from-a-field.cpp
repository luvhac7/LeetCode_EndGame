class Solution {
public:
typedef long long ll;
int mod=1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        unordered_set<int>s1,s2;
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        for(int i=0;i<h.size();i++)
        {
            for(int j=i+1;j<h.size();j++)
            {
                s1.insert(h[j]-h[i]);
            }
        }
        for(int i=0;i<v.size();i++)
        {
            for(int j=i+1;j<v.size();j++)
            {
                s2.insert(v[j]-v[i]);
            }
        }
        ll ans=0;
        for(auto i:s1)
        {
            if(s2.find(i)!=s2.end())
            {
                ll k=(ll)i*i;
                if(k>ans)
                {
                    ans=k;
                }
               // ans=max(ans,k);
            }
        }
        if(ans==0) return -1;
        ans=ans%mod;
        return ans;

    }
};