class Solution{
public:
static const int MOD=1e9+7;
typedef long long ll;
int concatenatedBinary(int n){
ll x=0;int len=0;
for(int i=1;i<=n;i++){
if((i&(i-1))==0)len++;
x=((x<<len)%MOD+i)%MOD;
}
return (int)x;
}
};