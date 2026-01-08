class Solution {
public:
    int canCompleteCircuit(vector<int>& g, vector<int>& c) {
        int n=g.size();
        int st=n-1;
        int end=n-1;
        int visit=0;
        int bal=0;
        while(visit<n){
            bal+=g[end]-c[end];
            visit++;
            end=(end+1)%n;
            while(bal<0 && visit<n){
                st--;
                bal+=g[st]-c[st];
                visit++;

            }
        }
        return bal<0 ?-1:st;
    }
};