class Solution {
public:
string f(string s)
{
    unordered_map<char,int>f;
    for(char c:s)f[c]++;
    priority_queue<pair<int,char>>pq;
    for(auto &it:f)
    {
        pq.push({it.second,it.first});
    }
    string ans="";
    while(!pq.empty())
    {
        auto top=pq.top();pq.pop();
        ans.append(top.first,top.second);
    }
    return ans;
}
    string frequencySort(string s) {
        // unordered_map<char,int>f;
        // for(char c:s) f[c]++;
        // string ans="";
        // for(auto &it:f)
        // {

        //     int x=it.second;
        //    // cout<<res<<" ";
        //     string y="";
        //     for(int i=0;i<it.second;i++){y+=it.first;ans+=y;y.clear();cout<<ans<<" ";}
        //   //  cout<<y<<" ";
        // }
        // return ans;
        return f(s);
    }
};