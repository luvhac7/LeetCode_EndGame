class Solution {
public:
typedef long long ll;
    int mySqrt(int x) {
if(x==0||x==1) return x;
int start=1,end=x,mid=-1;
while(start<=end)
{
    mid=start+(end-start)/2;
    ll square=static_cast<ll>(mid)*mid;
    if(square>x)
        end=mid-1;
    else if(square==x)
        return mid;
    else
        start=mid+1;
}
return static_cast<int>(round(end));
    }
};