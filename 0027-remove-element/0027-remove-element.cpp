class Solution {
public:
int x=0;
vector<int>ans;
    int removeElement(vector<int>& a, int v) {
        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=v){
                a[x]=a[i];x++;
            }
        }
        return x;
    }
};