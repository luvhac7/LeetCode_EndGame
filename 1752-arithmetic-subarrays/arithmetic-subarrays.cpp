class Solution {
public:
typedef vector<int> vi;
typedef vector<bool> vb;
    vector<bool> checkArithmeticSubarrays(vector<int>& a, vector<int>& l, vector<int>& r) {
        vb ans;
        for(int i=0;i<l.size();i++)
        {
            vi x(a.begin()+l[i],a.begin()+1+r[i]);
            sort(x.begin(),x.end());
            bool f=true;
            int d=x[1]-x[0];
            for(int j=2;j<x.size();j++)
            {
                if(x[j]-x[j-1]!=d)
                {
                    f=false;
                    break;
                }
            }
    ans.push_back(f);
            }

    return ans;
        }

};