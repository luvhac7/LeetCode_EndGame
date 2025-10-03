class Solution {
public:
    int hIndex(vector<int>& cit) {
        int n=cit.size();
        int h=0;
        sort(cit.begin(),cit.end());
        for(int i=0;i<cit.size();i++)
        {
             int hi=n-i;
            if(cit[i]>=hi)
            {
                h=hi;
                break;
            }
        }
        return h;
    }
};