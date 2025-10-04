typedef long long ll;
class Solution {
public:
    vector<vector<int>>ans;
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-3;i++)
        {
            for(int j=i+1;j<n-2;j++)
            {
                int k=j+1,l=n-1;
                
                  //  for(int l=k+1;l<n;l++)
                   while(k<l) 
                    {
                        ll sum=(ll)nums[i]+nums[j]+nums[k]+nums[l];
                        if(sum==target)
                        {
                            vector<int>temp={nums[i],nums[j],nums[k],nums[l]};                            st.insert(temp);
                            k++;
                            l--;
                        }
                        else if(sum<target){
                            k++;
                        }
                        else{
                            l--;
                        }
                    }
                }
            
        }
        for(auto &it:st) ans.push_back(it);
        return ans;
    }
};