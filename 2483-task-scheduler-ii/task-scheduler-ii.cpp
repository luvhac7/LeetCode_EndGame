class Solution {
public:
typedef long long ll;
    long long taskSchedulerII(vector<int>& a, int n) {
        map<int,ll>last;
        ll day=0;
        for(int i:a)
        {
            day++;
            if(last.count(i) && day-last[i]<=n)
            {
                day=last[i]+n+1;
            }
            last[i]=day;
        } 
        return day;
    }
};