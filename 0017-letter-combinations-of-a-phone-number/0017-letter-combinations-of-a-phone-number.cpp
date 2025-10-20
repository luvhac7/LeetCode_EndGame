class Solution {
public:
    vector<string> letterCombinations(string digits) {
        queue<string>q;
        vector<string>mp={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        q.push("");
        vector<string>ans;
        while(!q.empty())
        {
            string prefix=q.front();
            q.pop();
            if(prefix.size()==digits.size())
            {
                ans.push_back(prefix);
            }
            else{
                int no=digits[prefix.length()]-'0';
                if(no<2 || no>9)
                {
                    continue;
                }
                for(char i:mp[no])
                {
                    q.push(prefix+i);
                }

            }
        }
        return ans;

    }
};