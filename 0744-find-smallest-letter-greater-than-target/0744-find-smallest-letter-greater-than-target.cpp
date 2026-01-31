class Solution {
public:
    char nextGreatestLetter(vector<char>& le, char t) {

const int n=le.size();
int l=0,r=n-1,ans=n;
while(l<=r)
{
    int m=(r+l)/2;
    if(t<le[m])
    {
        ans=m;
        r=m-1;
    }
    else{
        l=m+1;
    }
}
return le[ans%n];
    }
};