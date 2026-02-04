class Solution {
public:
    int totalFruit(vector<int>& a) {
       /*
       BF
        int n=a.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            unordered_set<int>st;
            for(int j=i;j<n;j++)
            {
                st.insert(a[j]);
                if(st.size()>2) break;
                ans=max(ans,j-i+1);
            }
        }
        return ans;
        */
        //optimal


        unordered_map<int,int>mp;
        int l=0,ans=0;
        for(int r=0;r<a.size();r++)
        {
            mp[a[r]]++;
            while(mp.size()>2)
            {
                mp[a[l]]--;
                if(mp[a[l]]==0)
                {
                    mp.erase(a[l]);
                }
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;

    }
};