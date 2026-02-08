class Solution {
public:
typedef long long ll;
int cntpair(vector<int>&a,int low,int mid,int high)
{
    int cnt=0;
    int r=mid+1;
    for(int i=low;i<=mid;i++)
    {
        while(r<=high && (ll)a[i]>2LL*a[r])
        {
            r++;
        }
        cnt+=(r-(mid+1));
    }
    return cnt;
}
void merge(vector<int>&a,int low,int mid,int high)
{
vector<int>temp;
int l=low,r=mid+1;
while(l<=mid && r<=high)
{
    if(a[l]<=a[r]) temp.push_back(a[l++]);
    else temp.push_back(a[r++]);
}
while(l<=mid) temp.push_back(a[l++]);
while(r<=high) temp.push_back(a[r++]);
for(int i=low;i<=high;i++) a[i]=temp[i-low];
}
int ms(vector<int>&a,int l,int h)
{
    int cnt=0;
    if(l>=h) return cnt;
    int mid=l+(h-l)/2;
    cnt+=ms(a,l,mid);
    cnt+=ms(a,mid+1,h);
    cnt+=cntpair(a,l,mid,h);
    merge(a,l,mid,h);
    return cnt;
}
    int reversePairs(vector<int>& a) {
        //bf->o(n^2)
        // int n=a.size(),cnt=0;
        // for(int i=0;i<n;i++)
        // {
        // for(int j=0;j<i-1;j++)
        // {
        // if(a[j]>2*a[i])
        // {
        //     cnt++;
        // }
        // }
        // }
        // return cnt;
        return ms(a,0,a.size()-1);


    }
};