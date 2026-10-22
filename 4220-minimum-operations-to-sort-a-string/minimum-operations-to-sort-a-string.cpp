class Solution {
public:
    int minOperations(string s) {
        string sref=s,s1=s,s2=s;
        int cnt=0;
        vector<bool> freq(26,0);
        for(char c:s){
            if(!freq[c-'a'])cnt++,freq[c-'a']=1;
        }
        sort(sref.begin(),sref.end());
        if(sref==s)return 0;
        if(s.length()==2)return -1;
        sort(s2.begin()+1,s2.end());
        sort(s1.begin(),s1.end()-1);
        if(s[0]==sref[0]||s.back()==sref.back())return 1;
        if(sref[0]==s1[0]||sref.back()==s2.back())return 2;
        return 3;
    }
};