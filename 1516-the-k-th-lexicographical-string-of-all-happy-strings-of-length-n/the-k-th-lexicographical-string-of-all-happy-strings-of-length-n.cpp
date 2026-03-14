class Solution {
public:
    set<string>st;
    void solve(int n,int k,string s,int i)
    {
        if(i==n)
        {
            st.insert(s);   
            return;
        }
        if(i>=n) return;

        for(char c='a';c<='c';c++)
        {
            if (!s.empty() && s.back() == c) continue;
            s.push_back(c);
            // if(st.count(s)==0)
            // {
                solve(n,k,s,i+1);
                s.pop_back();
            // }
        }
    }
    string getHappyString(int n, int k) {
        
        solve(n,k,"",0);
        if (k > st.size()) return "";
        auto it=st.begin();
        advance(it,k-1);
        return *it;
    }
};