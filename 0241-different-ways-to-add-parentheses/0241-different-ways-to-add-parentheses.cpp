class Solution {
public:
int solve(int x,int y,char op)
{
    if(op=='+') return x+y;
    if(op=='-')return x-y;
    if(op=='*') return x*y;
    if(op=='/') return x/y;
    return 0;
}
    vector<int> diffWaysToCompute(string exp) {
        vector<int>res;
        bool f=1;
        for(int i=0;i<exp.size();i++)
        {
            if(!isdigit(exp[i]))
            {
                f=0;
                vector<int>l=diffWaysToCompute(exp.substr(0,i));
                vector<int>r=diffWaysToCompute(exp.substr(i+1));
                for(int x:l)
                {
                    for(int y:r)
                    {
                        int val=solve(x,y,exp[i]);
                        res.push_back(val);
                    }
                }
            }

        }
        if(f==1) res.push_back(stoi(exp));
        return res;
    }
};