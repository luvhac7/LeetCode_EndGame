class Solution {
public:
    int totalWaviness(int x, int y) {
        int o=0;
        for(int i=x;i<=y;i++)
        {
            string l=to_string(i);
            for(int j=1;j+1<l.size();j++)
            {
        if((l[j]<l[j-1]&&l[j]<l[j+1])||(l[j]>l[j-1]&&l[j]>l[j+1])) o++;
            }
        }
        return o;
    }
};