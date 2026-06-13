class Solution {
public:
    int largestRectangleArea(vector<int>&a) {
        stack<int>st;st.push(-1);
        int maxi=0;
        for(int i=0;i<a.size();i++)
        {
            while(st.top()!=-1 && a[i]<=a[st.top()])
            {
                int h=a[st.top()];st.pop();
                int w=i-st.top()-1;
                maxi=max(maxi,h*w);
            }
            st.push(i);
        }
        while(st.top()!=-1)
        {
            int h=a[st.top()];st.pop();
            int w=a.size()-st.top()-1;
            maxi=max(maxi,h*w);
        }
        return maxi;
    }
};