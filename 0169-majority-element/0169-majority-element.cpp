class Solution {
public:
    int majorityElement(vector<int>& a) {
        int cnt=0,can=0;
        for(int i:a)
        {
            if(cnt==0){
                can=i;
            }
            cnt+=(i==can)? 1:-1;
        }
        return can;
        
            }
};