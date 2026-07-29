class Solution {
public:
    string smallestPalindrome(string s, int k) {
        int n=s.size();
        vector<int>cnt(26,0);
        for(char c:s)cnt[c-'a']++;
        int mid=-1;
        vector<int>half(26,0);
        int halflen=0;
        for(int i=0;i<26;i++){
            if(cnt[i]&1)mid=i;
            half[i]=cnt[i]/2;
            halflen+=half[i];
        }
        long long cap=2e6;
        auto multinom=[&](vector<int>&h)->long long{
            int total=0;
            for(int x:h)total+=x;
            long long res=1;
            int used=0;
            for(int i=0;i<26;i++){
                if(h[i]==0)continue;
                long long c=1;
                int nn=total-used,rr=h[i];
                for(int t=1;t<=rr;t++){
                    c=c*(nn-rr+t)/t;
                    if(c>cap){
                        c=cap;
                        break;
                    }
                }
    res*=c;
    if(res>cap)res=cap;
    used+=h[i];
            }

            return res;
        };
       if(multinom(half)<k)return "";
       string lefthalf="";
       long long kk=k;
       for(int pos=0;pos<halflen;pos++){
        for(int c=0;c<26;c++){
            if(half[c]==0)continue;
            half[c]--;

            long long ways=multinom(half);
            if(kk<=ways){
                lefthalf+=('a'+c);
                break;
            }
            else {
                kk-=ways;
                half[c]++;
            }
        }


       }
       string result=lefthalf;
       if(mid!=-1)result+=('a'+mid);
       string rev=lefthalf;
       reverse(rev.begin(),rev.end());
       result+=rev;
       return result;
      
    }
};