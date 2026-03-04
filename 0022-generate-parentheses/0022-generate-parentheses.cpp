class Solution {
public:
void solve(string op,int st,int end,vector<string>&res)
{
    if(st==0 && end==0){
        res.push_back(op);return;
    }
    if(st==end){
        string op1=op;
        op1.push_back('(');
        solve(op1,st-1,end,res);
    }
    else if(st==0){
        string op1=op;
        op1.push_back(')');
        solve(op1,st,end-1,res);
    }
    else if(end==0){
        string op2=op;
        op2.push_back('(');
        solve(op2,st-1,end,res);
    }
    else{
        string op1=op,op2=op;
        op1.push_back('(');op2.push_back(')');
        solve(op1,st-1,end,res);
        solve(op2,st,end-1,res);
    }
}
    vector<string> generateParenthesis(int n) {
        int st=n,end=n;
        vector<string>res;
        string op="";
        solve(op,st,end,res);
        return res;
    }
};