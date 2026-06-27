class Solution {
public:
typedef long long ll;
    int distinctPrimeFactors(vector<int>& a ) {
        // ll p=1;set<int>st;
        // for(int i:a) p*=i;
        // for(int i=1;i<1000;i++)
        // {
        //     for(int j=0;j<a.size();j++)
        //     {
        //        if(a[j]%i) st.insert(a[j]);
        //     }
        // }
        // return st.size();
    //     vector<int> factors;
    //     int n=a.size();
    // // Loop only up to the square root of n
    // for (int i = 1; i * i <= n; ++i) {
    //     if (n % i == 0) {
    //         factors.push_back(i); // Add the smaller factor
            
    //         // Avoid duplicating the square root if it is a perfect square
    //         if (i != n / i) {
    //             factors.push_back(n / i); // Add the matching larger factor
    //         }
    //     }
    // }
    //     set<int>st;
    //     for(int i:factors) st.insert(i);
    //     return st.size();
  set<int>st;int n=a.size();
for(int n:a){  for(int i=2;i*i<=n;i++)
  {
    if(n%i==0)
    {
        st.insert(i);
        while(n%i==0)
        {
            n/=i;
    }
    }
  }
  if(n>1) st.insert(n);
  
}return st.size();
    }
};