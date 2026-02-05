class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        set<int>st;
        int res=0;
        for(int i:a) st.insert(i);
        for(int i:a)
        {
        if(st.find(i)!=st.end()&&st.find(i-1)==st.end())
        {
            int cur=i,cnt=0;
            while(st.find(cur)!=st.end())
            {
                st.erase(cur);cnt++;cur++;
            }
            res=max(res,cnt);
        }
        }
        return res;
      
    }
};