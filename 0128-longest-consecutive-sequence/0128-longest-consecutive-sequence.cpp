class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        // int ans=1,cnt=1;
        // int n=a.size();
        // if(a.empty()) return 0;
        // // int mini=*min_element(a.begin(),a.end());
        // // int maxi=*max_element(a.begin(),a.end());
        // sort(a.begin(),a.end());
        // for(int i=1;i<a.size();i++)
        // {
        //     if(a[i]==a[i-1]) continue;
        //     if(a[i]==a[i-1]+1)
        //     {
        //         cnt++;
        //     }
        //     else{
        //         ans=max(ans,cnt);
        //         cnt=1;
        //     }
        // }
        // return max(cnt,ans);

//--------------------O(N)-----------------------------
unordered_set<int>st;for(int i:a) st.insert(i);
int y=0;
for(int i:a)
{
    if(st.find(i)!=st.end())
    {
        if(st.find(i-1)==st.end())
        {
            int cur=i,x=0;
            while(st.find(cur)!=st.end()){
            st.erase(cur);
         //   i++;
           cur++;
            x++;
         //   y++;
        }
    
        y=max(y,x);
    }
    }
}
return y;





    }
};