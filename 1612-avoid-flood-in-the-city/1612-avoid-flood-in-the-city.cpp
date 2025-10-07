class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int>ans;
        int n=rains.size();
        map<int,int>fullakes;
        set<int>drydays;
        for(int i=0;i<n;i++)
        {
            if(rains[i]==0)
            {
                drydays.insert(i);
                ans.push_back(1);
            }
            else{
                int lake=rains[i];
                if(fullakes.find(lake)!=fullakes.end()){
                    auto it=drydays.lower_bound(fullakes[lake]);
                    if(it==drydays.end()){
                        return {};
                    }
                    int dryday=*it;
                    ans[dryday]=lake;
                    drydays.erase(dryday);

                }
                fullakes[lake]=i;
                ans.push_back(-1);
            }
        }
        return ans;
    }
};