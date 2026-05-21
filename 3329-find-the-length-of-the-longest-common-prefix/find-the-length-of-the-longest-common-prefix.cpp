class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        unordered_map<string,int>mp1;
        
        for(int i=0;i<n;i++){
            string s1="";
            string s=to_string(arr1[i]);
            for(int j=0;j<s.size();j++){
            s1+=s[j];
            mp1[s1]++;
            }
        }
        int ans=0;
        for(int i=0;i<arr2.size();i++){
            int x=arr2[i];
            string s=to_string(x);
            int sz=s.size();
            string str="";
            for(int j=0;j<sz;j++){
                str+=s[j];
                int len=str.size();
                
                if(mp1.find(str)!=mp1.end()){
                    ans=max(ans,len);
                }
            }
        }
        unordered_map<string,int>mp2;
        
        for(int i=0;i<arr2.size();i++){
            string s2="";
            string s=to_string(arr2[i]);
            for(int j=0;j<s.size();j++){
            s2+=s[j];
            mp2[s2]++;
            }
        }
        for(int i=0;i<arr1.size();i++){
            int x=arr1[i];
            string s=to_string(x);
            int sz=s.size();
            string str="";
            for(int j=0;j<sz;j++){
                str+=s[j];
                int len=str.size();
                
                if(mp2.find(str)!=mp2.end()){
                    ans=max(ans,len);
                }
            }
        }
        return ans;
    }
};