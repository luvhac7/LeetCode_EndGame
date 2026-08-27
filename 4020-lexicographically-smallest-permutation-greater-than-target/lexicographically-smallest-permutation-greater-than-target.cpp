class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        int n=s.size();
        sort(s.begin(),s.end());
        if(s[0]>t[0])return s;
        if(s[n-1] < t[0])return "";
        int p=-1;
        for(int i=0;i<n;++i){
            string op="";
            map<char,int>mp;
            for(auto &j:s)mp[j]++;
            bool flag=true;
            for(int j=0;j<i;++j){
                if(mp.count(t[j]) && mp[t[j]]>0){
                    op.push_back(t[j]);
                    mp[t[j]]--;
                    if(mp[t[j]]==0){
                        mp.erase(t[j]);
                    }
                }else{
                    flag=false;
                    break;
                }
            }
            if(!flag){
                continue;
            }
            auto it=mp.upper_bound(t[i]);
            if(it==mp.end()){
                flag=false;
            }else{
                char c=it->first;
                int f=it->second;
                if(f>0){
                    op.push_back(c);
                    mp[c]--;
                    if(mp[c]==0)mp.erase(c);
                    for(auto &j:mp){
                        if(j.second > 0){
                            for(int k=0;k<j.second;++k){
                                op.push_back(j.first);
                            }
                        }
                    }
                }else{
                    flag=false;
                }
            }
            if(!flag){
                continue;
            }
            p=i;
        }
        if(p==-1)return "";
        string op="";
        map<char,int>mp;
        for(auto &j:s)mp[j]++;
        for(int i=0;i<p;++i){
            op.push_back(t[i]);
            mp[t[i]]--;
            if(mp[t[i]]==0)mp.erase(t[i]);
        }
        auto it=mp.upper_bound(t[p]);
        char c=it->first;
        int f=it->second;
        op.push_back(c);
        mp[c]--;
        for(auto &j:mp){
            if(j.second > 0){
                for(int k=0;k<j.second;++k){
                    op.push_back(j.first);
                }
            }
        }
        return op;
    }
};