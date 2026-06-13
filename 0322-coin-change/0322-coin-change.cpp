class Solution {
public:
    int coinChange(vector<int>& sikka, int paisa) {
        vector<int>pocket(paisa+1,paisa+1);
        pocket[0]=0;
        for(int i=1;i<=paisa;i++)
        {
            for(int p:sikka)
            {
                if(i-p>=0)
                {
pocket[i]=min(pocket[i],pocket[i-p]+1);
                }
            }
        }
        return pocket[paisa]>paisa ? -1:pocket[paisa];
    }
};