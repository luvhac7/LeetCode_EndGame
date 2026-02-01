class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        a.erase(remove_if(a.begin(),a.end(),[](int n){return n<=0;}),a.end());
        sort(a.begin(),a.end());
        int tar=1;
        for(int i:a)
        {
            if(i==tar){
                tar+=1;
            }
            else if(i>tar)
            {
                return tar;
            }
        }
        return tar;
    }
};