
long long rmin(int i, int ss, int se, int l, int r, vector<int>& ST){
    if(i>=ST.size()) return INT_MAX;

    if(se<l || ss>r) return INT_MAX;
    else if(ss>=l && se<=r) return ST[i];
    else{
        int mid = (ss+se)/2;
        return min(rmin(2*i+1,ss,mid,l,r,ST),rmin(2*i+2,mid+1,se,l,r,ST));
    }
}

long long rmax(int i, int ss, int se, int l, int r, vector<int>& ST){
    if(i>=ST.size()) return INT_MIN;

    if(se<l || ss>r) return INT_MIN;
    else if(ss>=l && se<=r) return ST[i];
    else{
        int mid = (ss+se)/2;
        return max(rmax(2*i+1,ss,mid,l,r,ST),rmax(2*i+2,mid+1,se,l,r,ST));
    }
}

long long getvalue(pair<int,int> interval, vector<int>& STmin, vector <int>& STmax, int m){
    int l = interval.first;
    int r = interval.second;

    return rmax(0,0,m-1,l,r,STmax) - rmin(0,0,m-1,l,r,STmin);
}

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        int m = (n==1)? 2:1;
        long long ans = 0;

        while(m<n)m*=2;

        vector <int> STmin(2*m-1,INT_MAX);
        vector <int> STmax(2*m-1,INT_MIN);

        for(int i = 0;i<n;i++){
            STmin[m-1+i] = nums[i];
            STmax[m-1+i] = nums[i];
        }

        for(int i = m-2;i>=0;i--){
            STmin[i] = min(STmin[2*i+1],STmin[2*i+2]);
            STmax[i] = max(STmax[2*i+1],STmax[2*i+2]);
        }

        set <pair<int,int>> used;
        priority_queue <vector<long long>> subs; //(value of subarray, l, r);

        subs.push({*max_element(nums.begin(), nums.end())-*min_element(nums.begin(),nums.end()),0,n-1});

        while(k && !subs.empty()){
            vector <long long> top = subs.top();
            subs.pop();

            pair<int,int> subarray = {top[1],top[2]};
            

            if(used.find(subarray) == used.end()){
                ans += top[0]; k--;
                used.insert({subarray});

                subs.push({getvalue({subarray.first, subarray.second-1},STmin, STmax,m),subarray.first,subarray.second-1});
                subs.push({getvalue({subarray.first+1, subarray.second},STmin, STmax,m),subarray.first+1,subarray.second});

            }

        }
        return ans;

    }
};