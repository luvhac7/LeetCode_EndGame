class Solution {
public:
/*
inti:
pile>=max_element
1:[5,10,3],k=4
->take:a[0]=5->pile 
->10%pile=2->cnt
->3>5 so cnt=1
check pile>a[i] then cnt=1
else cnt+=a[i]%pile

*/
//---------------Brute-force---(speed* j)----------------
 typedef long long ll;
// int solve(vector<int>&a,int h)
// {
//     int maxi=*max_element(a.begin(),a.end());
//    for(int speed=1;speed<=maxi;seed++)
//    {
//     ll ans=0;
//     for(int j=0;j<a.size();j++)
//     {
//         ans+=(a[j]+speed-1)/speed;
//     }
//     if(ans<=h) return speed;
//    }
//    return maxi;
// }

//-----------Optimal
bool ok(vector<int>&a,int h,int m)
{
ll res=0;
for(int i=0;i<a.size();i++)
{
res+=(a[i]+m-1)/m;
}
return res<=h;
}
int bs(vector<int>&a,int k)
{
    int l=1,h=*max_element(a.begin(),a.end());
    int res=h;
    while(l<=h)
    {
        int m=l+(h-l)/2;
        if(ok(a,k,m))
        {
            res=m;h=m-1;
        }
        else{
            l=m+1;
        }
    }
    return res;
}
    int minEatingSpeed(vector<int>& a, int h) {
       // return solve(a,h);
       return bs(a,h);
    }
};