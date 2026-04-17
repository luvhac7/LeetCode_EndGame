class Solution {
public:
    int minMirrorPairDistance(vector<int>& a) {
        int x=1e9,i=0;
        unordered_map<int,int>f;
        for(int &n:a)
        {
            int r;if(f.count(n)) x=min(x,i-f[n]);
            for(r=0;n;n/=10)
                r=r*10+(n%10);
            f[r]=i++;
        }
        return -(x==1e9) | x;
    }
};