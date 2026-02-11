class Solution {
public:
typedef long long ll;
int x=0;
    int longestBalanced(vector<int>& a) {
        int n=a.size();
        int res=0;
        for(int i=0;i<n;i++)
         {
        //     unordered_set<int>o,e;
        //     for(int j=i;j<n;j++)
        //     {
        //         if(a[j]&1) o.insert(a[j]);
        //         else e.insert(a[j]);
        //         if(o.size()==e.size()) res=max(res,j-i+1);
        //     }
        set<int>st;int o=0,e=0;
        for(int j=i;j<n;j++)
        {
            if(!st.count(a[j]))
            {
                if(a[j]%2==0) e++;
                else o++;
                st.insert(a[j]);
            }
            if(o==e) x=max(x,j-i+1);
        }
        }
        return x;
    }
};