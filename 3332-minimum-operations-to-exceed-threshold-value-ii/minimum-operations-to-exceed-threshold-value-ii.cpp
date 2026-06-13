class Solution {
public:
typedef long long ll;
int f(vector<int>&a,int k)
{
priority_queue<ll,vector<ll>,greater<>>pq(a.begin(),a.end());
int ans=0;
while(pq.top()<k)
{
    ll x=pq.top();pq.pop();
    ll y=pq.top();pq.pop();
    pq.push(2*x+y);
    ans++;
}
return ans;
}
    int minOperations(vector<int>&a, int k) {
        return f(a,k);
    }
};