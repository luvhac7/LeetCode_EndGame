class Solution {
public:
    int minimumDeletions(vector<int>& A) {
    int a=max_element(begin(A),end(A))-begin(A);
    int b=min_element(begin(A),end(A))-begin(A);
    int n=A.size();
    if(a>b) swap(a,b);
    return min({a+1+n-b,b+1,n-a});
    }
};