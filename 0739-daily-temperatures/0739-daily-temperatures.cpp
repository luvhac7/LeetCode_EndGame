class Solution {
public:
/*
app:
usse a stacl
res(n,0)
a[i]>a[st.top()]
    then idx=st.top();
    st.pop();
    res[idx]=i-idx; //i -> 0 se n
st.push(i);

*/
typedef vector<int> vi;
    vi dailyTemperatures(vi& a) {
        int n=a.size();
       vi res(n,0);
       stack<int>st;
       for(int i=0;i<n;++i)
       {
        while(!st.empty() && a[st.top()]<a[i])
        {
            int idx=st.top();st.pop();
            res[idx]=i-idx;
        }
        st.push(i);
       }
       return res;
    }
};