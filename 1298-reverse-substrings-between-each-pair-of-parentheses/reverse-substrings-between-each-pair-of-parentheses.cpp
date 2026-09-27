class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<char>st;
        for(int i=0; i<n; i++){
            if(s[i]!=')'){
                st.push(s[i]);
            }
            else{
                string ans="";
                while(st.top()!='('){
                    ans+=st.top();
                    st.pop();
                }
                st.pop();
                for(int j=0; j<ans.size(); j++){
                    st.push(ans[j]);
                }
            }
        }
        string ansf="";
        while(st.size()>0){
            ansf+=st.top();
            st.pop();
        }
        reverse(ansf.begin(),ansf.end());
        return ansf;
    }
};