class Solution {
public:
typedef vector<int> vi;
int f(vi &a,int n)
{
map<int,int>sidx;//sum_idx
sidx[0]=-1;
int maxi=0,rs=0;//max_len , remain sum
for(int i=0;i<n;i++)
{
rs+=(a[i]==1) ? 1:-1;
if(sidx.find(rs)!=sidx.end()){
    maxi=max(maxi,i-sidx[rs]);
}
else{
    sidx[rs]=i;
}
}
return maxi;
}
int f1(vi& a,int n)
{
    int mx=0;
    for(int i=0;i<n;i++)
    {
        int z=0,o=0;
        for(int j=i;j<n;j++)
        {
            if(a[j]==0)
                z++;
            else o++;
        if(z==o)
            mx=max(mx,j-i+1);
        }
    }
    return mx;
}
int f2(vi &a,int n)
{
    if(a.empty()) return 0;
    int cnt=1;
    vector<pair<int,int>>block;
    for(int i=0;i<n;i++)
    {
        if(i==a.size()-1 || a[i]!=a[i+1]){
            block.push_back({a[i],cnt});
            cnt=1;
        }
        else{
            cnt++;
        }
    }
    int mx=0;
    for(size_t i=0;i<block.size()-1;i++)
    {
        int cur=2*min(block[i].second,block[i+1].second);
        mx=max(mx,cur);
    }
    return mx;
}
    int findMaxLength(vector<int>& a) {
       int n=a.size();
       return f(a,n);
    }
};
