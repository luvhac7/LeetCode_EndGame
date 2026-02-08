class Solution {
public:
    vector<int> replaceElements(vector<int>& a) {
        vector<int>r;
        int n=a.size();        
        int maxi=a[n-1];
        r.push_back(-1);
        for(int i=n-2;i>=0;i--)
        {
       //     r.push_back(maxi);
            // if(a[i]>maxi)
            // {
             
                r.push_back(maxi);
                maxi=max(maxi,a[i]);
            
            // if(maxi<=a[i])
            // {
            //     maxi=a[i];
            //     r.push_back(a[i]);
            //     cout<<a[i]<<"\n";
            // }
            // else{
            //     r.push_back(maxi);
            //     cout<<maxi;
            // }
        }
        reverse(r.begin(),r.end());
        return r;
        
    }
};