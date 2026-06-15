class Solution {
public:
void f(vector<int>&a,int t,int i,vector<vector<int>>&ans,vector<int>&temp)
{
 int n=a.size();
 if(t==0){
    ans.push_back(temp);
    return ;
 }   
 if(t<0 || i>=a.size()) return;
 temp.push_back(a[i]);
 f(a,t-a[i],i,ans,temp);
 temp.pop_back();
 f(a,t,i+1,ans,temp);
}
    vector<vector<int>> combinationSum(vector<int>& can, int tar) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(can,tar,0,ans,temp);
        return ans;
    }
};