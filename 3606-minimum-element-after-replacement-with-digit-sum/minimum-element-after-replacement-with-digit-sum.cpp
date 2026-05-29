class Solution {
public:
int ds(int n)
{
    int s=0;
    while(n>0)
    {
        s+=n%10;
        n/=10;
    }
    return s;
}
    int minElement(vector<int>&a) {
        //vector<int>res;
        //for(int i:a)
        //{
          //  string x=to_string(i);
            //int sum=0;
            //for(char c:x)
            //{{
              //  sum+=c-'0';
           // }
            //res.push_back(sum);
            //}
        //}
   //int r=*min_element(res.begin(),res.end());
   int mini=INT_MAX;
   for(int i:a)
   {
    int cur=ds(i);
    mini=min(mini,cur);
   }
   return mini;
    }

};