class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int v=0,x=0;
        for(int i=0;i<op.size();i++)
        {
            if(op[i]=="--X"|| op[i]=="X--")
            {
                x+=v--;
            }
            if(op[i]=="++X" || op[i]=="X++")
            {
                x+=v++;
            }
        }
        return v;
    }
};