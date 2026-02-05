class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& a) {
        //bf
        unordered_map<string,int>mp;
        vector<vector<string>>res;
        for(int i=0;i<a.size();i++)
        {
            string s=a[i];
            sort(s.begin(),s.end());
            if(mp.find(s)==mp.end())
            {
                mp[s]=res.size();
                res.push_back({});
            }
            res[mp[s]].push_back(a[i]);
        }
        return res;
    }
};