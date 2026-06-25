class Solution {
public:
typedef vector<int> vi;
bool fn(int n)
{
    if(n<2) return false;
    for(int i=2;i*i<=n;i++) if(n%i==0) return false;
    return true;
}
    int maximumPrimeDifference(vector<int>&a) {
        // vi ans;
        // for(int i:a)
        // {
        //     if(f(i)) ans.push_back(i);
        // }
        // sort(ans.begin(),ans.end());
        // int f=ans[0],n=ans.size();
        // int l=ans[n-1];
        // return abs(f-l);
  int f=-1,l=-1,n=a.size();
  for(int i=0;i<n;i++)
  {
    if(fn(a[i]))
    {
        f=i;
        break;
    }
  }
  for(int i=n-1;i>=0;i--)
  {
    if(fn(a[i]))
    {
        l=i;
        break;
    }
  }
  return l-f;
    }
};