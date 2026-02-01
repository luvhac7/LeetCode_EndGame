class Solution {
public:
typedef long long ll;
    long long kSum(vector<int>& a, int k) {
        int n=a.size();
        ll maxi=0;
    vector<ll>subs;
    for(int &i:a){
        if(i>=0) maxi+=i;
        else i=abs(i);
    }
sort(a.begin(),a.end());
priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>>pq;
pq.push({a[0],0});
while(!pq.empty()&&subs.size()<k-1){
    pair<ll,int>top=pq.top();
    pq.pop();
    ll subt=top.first;
    int idx=top.second;
    subs.push_back(subt);
    if(idx<n-1){
        
        pq.push({subt + a[idx + 1], idx + 1});
pq.push({subt - a[idx] + a[idx + 1], idx + 1});
    }
}
vector<ll>ans;
ans.push_back(maxi);
for(ll subt:subs){
    ans.push_back(maxi-subt);
}
return ans[k-1];

    }

};