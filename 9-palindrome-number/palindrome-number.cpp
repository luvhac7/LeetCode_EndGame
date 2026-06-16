class Solution {
public:
vector<int>d;
bool neg=false;
bool check(vector<int>&A)
{
    int i=0,j=A.size()-1;
    while(i<j)
    {
        if(A[i]!=A[j]) return false;
        i++;j--;
    }
    return true;
}
    bool isPalindrome(int x) {
        if(x<0) {neg=true;}
        while(x>0)
        {
            d.push_back(x%10);x/=10;
        }
        if(neg) return false;
        for(int i:d) cout<<i<<" ";
        return check(d);
    }
};