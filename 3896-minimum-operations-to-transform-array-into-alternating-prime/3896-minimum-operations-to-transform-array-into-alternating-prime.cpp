class Solution {
public:
int pr(int n)
{
    if(n<2) return false;
    for(int i=2;i*i<=n;i++) if(n%i==0) return false;
    return true;
}
bool even(int n)
{
    if(n%2==0) return true;
    return false;
}
    int minOperations(vector<int>& a) {
        int cnt=0,n=a.size();
        for(int i=0;i<n;i++)
        {
            if(even(i) && !pr(a[i]))
            {
                int temp=a[i];
                while(!pr(temp))
                {
                    temp++;
                    cnt++;
                }
            }
            if(!even(i) && pr(a[i]))
            {
                if(a[i]==2)
                {
                    cnt+=2;
                }
                else{
                    cnt+=1;
                }
            }
        }
        return cnt;
    }
};