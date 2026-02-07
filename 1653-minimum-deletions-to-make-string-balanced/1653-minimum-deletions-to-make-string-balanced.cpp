class Solution {
public:
    int minimumDeletions(string s) {
        int b=0,n=s.size(),x=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='b') b++;
            else{
            if(b>0){
                b--;x++;
            }
            }
        }return x;
    }
};