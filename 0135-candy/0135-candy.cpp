class Solution {
public:
    int candy(vector<int>& a) {
        int n=a.size();
        if(n<=1) return n;
        int cnt=1;
        int u=0,d=0,p=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
            {
                u++;
                p=u;
                d=0;
                cnt+=1+u;
            }
            else if(a[i]<a[i-1])
            {
                u=0;
                d++;
                cnt+=1+d-(p>=d);
            }
            else{
                u=d=p=0;
                cnt+=1;
            }
        }
        return cnt;
    }
};