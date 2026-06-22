class Solution {
public:
typedef vector<int> vi;
typedef long long ll;
    int sumSubarrayMins(vector<int>& a) {
        // vector<int>ans;
        // int n=a.size();
        // for(int i=0;i<n;i++)
        // {
        //       ans.push_back(a[i]);
        //     for(int j=i;j<n;j++)
        //     {
        //         ans.push_back(a[j]);
        //       //  ans.push_back(a[i]);
        //     }
        // }
        // for(int &i:ans) cout<<i<<" ";
        // return ans[0];   

        /*
        totalsum cal ,mxi=1e9+7
        do stack s1 s2
        left right (n)
        i=0- >n 
        left[i]=i+1;
        right[i]=n-i;


         i=0- >n 
         while me !st.empty rhen && a[st.top()]>a[i] then
            s1.pop()
            }
            if(!s1.empty())
            {
            left[i]=i-st.top();
            }
            s1.push(i);
            }
            same for s2
            i=0 -> n
            while( !s2.empty() && a[s2.top()]>a[i])
            {
            right[s2.top()]=i-st.top();
            s2.pop();
            }s2.push(i);
            }

            cal contri
            for(int i=0;i<n;i++)
            {
            ll cnt=(left[i]*right[i])%M;
            cnt=(cnt*a[i])%M;
            total_sum=(total_sum+cnt)%M;

            }
            return total_sum
        */
        int n=a.size();
vi left(n),right(n);
stack<int>s;
for(int i=0;i<n;i++)
{
    while(!s.empty() && a[s.top()]>a[i]) s.pop();
    left[i]= s.empty() ? (i+1):(i-s.top());
    s.push(i);
}
while(!s.empty()) s.pop();
for(int i=n-1;i>=0;i--)
{
    while(!s.empty() && a[s.top()]>=a[i]) s.pop();
    right[i]=s.empty() ? n-i:(s.top()-i);
    s.push(i);
}
while(!s.empty()) s.pop();
ll sum=0,M=1e9+7;
for(int i=0;i<n;i++)
{
    ll cnt=(1LL * left[i] * right[i])%M;
    ll ways=( cnt * a[i])%M;
    sum=(sum+ways)%M;
}
return sum;
    }
};