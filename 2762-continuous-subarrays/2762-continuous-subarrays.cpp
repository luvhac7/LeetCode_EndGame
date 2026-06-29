class Solution {
public:
typedef long long ll;
    long long continuousSubarrays(vector<int>& a) {
        int n=a.size(),l=0;
        ll total=0;
        map<int,int>f;//for(int i:a)f[i]++;
        for(int r=0;r<n;r++)
        {
             f[a[r]]++;
            while(f.rbegin()->first-f.begin()->first>2)
            {
                f[a[l]]--;
                if(f[a[l]]==0)
                {
                    f.erase(a[l]);
                }
                l++;
            }
            total+=(r-l+1);
        }
        return total;
    }
};