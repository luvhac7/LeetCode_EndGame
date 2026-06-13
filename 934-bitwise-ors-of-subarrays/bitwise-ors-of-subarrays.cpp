class Solution {
public:
int f(vector<int>&a)
{
    set<int>s,t;
    for(int i:a)
    {
        set<int>x;
        t.insert(i);
        for(int j:t) x.insert(i|j);
        t=x;
        for(int j:t) s.insert(j);
    }
    return s.size();
}
int sol(vector<int>&a)
{set<int>st1,st2;
for(int i:a)
{
    set<int>temp;
    st2.insert(i);
    for(int j:st2) temp.insert(i|j); 
    st2=temp;
    for(int j:temp) st1.insert(j); 
}
return st1.size();

}
    int subarrayBitwiseORs(vector<int>& a) {  
        // int n=a.size();
        // if(n==1) return 1;
        return sol(a);
        // else return a[n-1]+a[n-2];
    }
};