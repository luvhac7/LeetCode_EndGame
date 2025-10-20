class Solution {
public:

    vector<string> letterCombinations(string d) {
        int n=d.size();
        if(d.empty()) return {};
        vector<string>maps={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        vector<string>ans;
        string path;
        function<void(int)>backtrack=[&](int idx)
        {
            if(idx==d.size())
            {
                ans.push_back(path);
                return;
            }
            string letter=maps[d[idx]-'0'];
            for(char c:letter)
            {
                path.push_back(c);
                backtrack(idx+1);
                path.pop_back();

            }
        };/*
        for(int i=0;i<n;i++)
        {
            
        }
        */
    backtrack(0);
    return ans;
    }
};