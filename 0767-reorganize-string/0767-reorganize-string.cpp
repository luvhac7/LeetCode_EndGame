class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>f;
        for(char i:s)f[i]++;
        priority_queue<pair<int,char>>pq;
        for(auto &p:f)
        {
            pq.push({p.second,p.first});
        }
        string ans="";
        pair<int,char>prev={0,'#'};
        while(!pq.empty())
        {
            auto cr=pq.top();pq.pop();
            ans+=cr.second;
            cr.first--;
            if( prev.first>0 )
            {
                pq.push(prev);
            }
            prev=cr;
        }
        return ans.size()==s.size() ? ans:"";
    }
};