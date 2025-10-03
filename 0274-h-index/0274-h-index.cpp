class Solution {
public:
    int hIndex(vector<int>& cit) {
        int no_of_papers=cit.size();
        sort(cit.begin(),cit.end());
        int hindx=0;
        for(int i=0;i<no_of_papers;i++)
        {
            int point=no_of_papers-i;
            if(cit[i]>=point)
            {
                hindx=point;
                break;
            }
        }
        return hindx;
    }
};