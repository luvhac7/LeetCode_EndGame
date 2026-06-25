class Solution {
public:
    int countMajoritySubarrays(vector<int>& a, int t) {
        // map<int,int>f;
        multiset<int>st;
        st.insert(0);
      //  f[0]=-1;
        int cs=0,cnt=0;
        for(int i=0;i<a.size();i++)
        {
            cs+=(a[i]==t) ?  1:-1;
            // if(f.find(a[i])!=f.end() )
            // {
            //     cnt++;
            // }
            // f[cs]=i;
            auto it=st.lower_bound(cs);
            cnt+=distance(st.begin(),it);
            st.insert(cs);
        }
        return cnt;
    }
};