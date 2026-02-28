class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
       vector<vector<int>>res;
       sort(a.begin(),a.end());
       for(int i=0;i<a.size();i++)
       {
        if(i>0&&a[i]==a[i-1]) continue;
        int j=i+1,k=a.size()-1;
        while(j<k)
        {
            int t=a[i]+a[k]+a[j];
            if(t>0)
            {
                k--;
            }
            else if(t<0)
            {
                j++;
            }
            else{
                res.push_back({a[i],a[j],a[k]});
                j++;
                while(a[j]==a[j-1] && j<k) j++;
            }
        }
       } 
       return res;
    }
};