class Solution {
public:
int bino(int n,int k)
{

int res=1;
    if(n-k<k)
    {
        k=n-k;
    }
    for(int i=0;i<k;i++)
    {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}
    vector<vector<int>> generate(int a) {
        vector<vector<int>>res;
     for(int i=0;i<a;i++)
     {
        vector<int>ans;
    for(int j=0;j<=i;j++){
        ans.push_back(bino(i,j));
     }   
     res.push_back(ans);
     }
     return res;
    }
};