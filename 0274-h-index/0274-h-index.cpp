class Solution {
public:
    int hIndex(vector<int>& c) {
        sort(c.begin(),c.end(),greater<int>());
        int h=0;
        int n=c.size();
        for(int i=0;i<n;i++)
        {
            if(c[i]>=i+1)
            {
                h++;
            }
            else{
                break;
            }
        }
        return h;
    }
};