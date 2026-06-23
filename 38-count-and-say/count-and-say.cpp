class Solution {
public:
    string countAndSay(int n) {
         string res="1";
         while(--n)
         {
            int len=res.size();
            string nxt="";
        for(int i=0;i<len;){
            int cnt=1;
            while(i+1<len && res[i]==res[i+1])
            {
                i++;cnt++;
            }
            nxt+=to_string(cnt)+res[i];
            i++;
         }
         res=nxt;
         }
         return res;
    }
};