class Solution {
public:
    int hIndex(vector<int>& c) {
        int h=0,n=c.size(),i=0; 
        for(int i=0;i<n;i++)
        {
            int x=n-i;//i++;
            if(c[i]>=x)
            {
                h=x;break;
            }
        }
        return h;
    }
};