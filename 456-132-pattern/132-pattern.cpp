class Solution {
public:
    bool find132pattern(vector<int>& a) {
        // int cnt=0,cnt2=0,cnt3=0;
        // for(int i:a)
        // {
        //     if(i==1) cnt++;
        //     else if(i==2) cnt2++;
        //     else if(i==3) cnt3++;
        // }
        // cout<<min({cnt,cnt2,cnt3});
        // return true;
    int n=a.size();
    stack<int>st;
    if(n<3) return false;
    int mini=INT_MIN;
    for(int i=n-1;i>=0;i--)
    {
        if(a[i]<mini) return true;
        while(!st.empty() && a[i]>st.top())
        {
            mini=st.top();st.pop();
        }
        st.push(a[i]);
    }
    return false;
    }
};