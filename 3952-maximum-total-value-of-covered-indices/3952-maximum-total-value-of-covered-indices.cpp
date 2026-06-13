class Solution {
public:
typedef long long ll;
    long long maxTotal(vector<int>& a, string s) {
        ll mini=INT_MAX,ans=0;int n=a.size();
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='1'){ans+=a[i];
            mini=min(mini,(ll)a[i]);
            }
    else{if(i+1<n && s[i+1]=='1')
        {
            ans+=a[i];
            mini=min(mini,(ll)a[i]);
            ans-=mini;
        }
        mini=INT_MAX;
    }
        }
        return ans;
    }
};