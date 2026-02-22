class Solution {
public:
    int binaryGap(int n) {
     bitset<32>b(n);
     string s=b.to_string();
     int x=0,r=-1;
     for(int i=0;i<32;i++)
     {
        if((n>>i)&1)
        {
            if(r!=-1)
            {
                x=max(x,i-r);
            }
            r=i;
        }
     }   
     return x;
    }
};