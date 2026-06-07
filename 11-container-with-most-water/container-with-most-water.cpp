class Solution {
public:
    int maxArea(vector<int>& a) {
        int x=0,y=a.size()-1;
        int ans=0;
        while(x<y)
        {
            int bich=y-x;
            int cur=min(a[x],a[y]);
            cout<<cur<<" "<<bich<<" ";
            ans=max(ans,bich*cur);
            if(a[x]<a[y]) x++;
            else y--;
        }
        return ans;
    }
};