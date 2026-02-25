class Solution {
public:
    vector<int> sortByBits(vector<int>& a) {
        vector<pair<int,int>>ans;
        int n=a.size();
        for(int &i:a)
        {
            int x=i,cnt=0;
            while(x){
                if(x&1){cnt++;}
                x>>=1;
            }
            ans.push_back({cnt,i});
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<n;i++)
        {
            a[i]=ans[i].second;
        }
        return a;
    }
};