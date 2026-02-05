class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& a) {

        int n=a.size();
        vector<int>res(n);
        for(int i=0;i<a.size();i++)
        {
          //  res[i]=a[((a[i]+i)%n+n)%n];
             res[i] = a[((i+a[i])%n+n)%n];
         /*   if(a[i]>0)
            {
                int idx=a[i];
                res.push_back(idx);
            }
             result[i] = nums[((i + nums[i]) % n + n) % n];
            if(a[i]<0)
            {
                int idx=abs(i);res.push_back(idx);
            }
            if(a[i]==0)
            {
                res.push_back(a[i]);
            }
        }
        */
        }
        return res;
    }
};