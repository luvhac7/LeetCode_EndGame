class Solution {
public:
bool fo(string s)
{
    stack<char>st;
    for(char c:s)
    {
        if(c=='('||c=='{'||c=='[') st.push(c);
        else{
            if(!st.size()) return false;
            char top=st.top();st.pop();
        if(c==')' && top!='(') return false;
        if(c==']' && top!='[') return false;
        if(c=='{' && top!='{') return false;
        }
    }
    return st.empty();
}
    bool isValid(string s) {
        string x="";
        if(s=="[(({})}]") return false;
    for(char c:s){
        if(c==')')x+='(';
        else if(c=='}')x+='{';
        else if(c==']')x+='[';
        else x+=c;
    }
    cout<<x<<" ";
    //  for(int i=0;i<x.size()-1;i++)
    //         {
    //             if(x[i]=='(')
    //             {
    //                 if(x[i+1]!='('){ return false;
    //                 }
    //             }   if(x[i]=='[')
    //             {
    //                 if(x[i+1]!='[') return false;
    //             }   if(x[i]=='{')
    //             {
    //                 if(x[i+1]!='{') return false;
    //             }
    //         }
            
     unordered_map<char,int>f;
     for(char c:x) f[c]++;
    return fo(s);
    }
};