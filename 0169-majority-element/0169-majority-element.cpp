class Solution {
public:
    int majorityElement(vector<int>& a) {
        int n=a.size(),cnt=0;
        sort(a.begin(),a.end());
        int x=a[n/2];
        for(int i:a)
        {
            if(i==x) cnt++;
        }
        if(cnt>n/2) return x;
        return -1;
    }
};