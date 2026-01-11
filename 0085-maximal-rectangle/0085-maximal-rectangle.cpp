class Solution {
public:
int solve(vector<int>&a)
{
    int n=a.size();
    stack<int>st;
   // int maxi=0;
    a.push_back(0);
    int ans=0;
    for(int i=0;i<=n;i++)
    {
        while(!st.empty() && a[st.top()]>a[i])
        {
            int h=a[st.top()];
            st.pop();
            int w=st.empty() ? i:i-st.top()-1;
            ans=max(ans,h*w);
        }
        st.push(i);
    }
    a.pop_back();
    return ans;
}
    int maximalRectangle(vector<vector<char>>& a) {
        int n=a.size();
        int m=a[0].size();
        int ans=0;
        vector<int>h(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j]=='1')
                {
                    h[j]++;
                }
                else{
                    h[j]=0;
                }
            }
            ans=max(ans,solve(h));
        }
        return ans;
    }
};