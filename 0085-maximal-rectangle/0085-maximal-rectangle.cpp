class Solution {
public:
    int area(vector<int>&a)
    {
        int n=a.size();
        stack<int>st;
        a.push_back(0);
        int maxi=0;
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() && (a[st.top()]>a[i]))
            {
                int h=a[st.top()];
                st.pop();
                int w=st.empty() ? i:i-st.top()-1;
                maxi=max(maxi,h*w);
            }
            st.push(i);
        }
        a.pop_back();
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& a) {
        int m=a.size();
        int n=a[0].size();
        vector<int>h(n,0);
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]=='1')
                    h[j]+=1;
                else{
                    h[j]=0;
                }
            }
            ans=max(ans,area(h));
        }
        return ans;
    }
};