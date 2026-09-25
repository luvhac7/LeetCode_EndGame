class Solution {
public:
    set<string> solve(string s) {
        set<string> res;
        int pos = -1, bal = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{') {
                if (bal == 0) pos = i;
                bal++;
            }
            else if (s[i] == '}') bal--;
            else if (s[i] == ',' && bal == 0) {
                string a = s.substr(0, i);
                string b = s.substr(i + 1);

                set<string> x = solve(a), y = solve(b);
                res.insert(x.begin(), x.end());
                res.insert(y.begin(), y.end());
                return res;
            }
        }

        if (pos == -1) {
            res.insert(s);
            return res;
        }

        int end = pos, b = 0;
        for (int i = pos; i < s.size(); i++) {
            if (s[i] == '{') b++;
            if (s[i] == '}') b--;
            if (b == 0) {
                end = i;
                break;
            }
        }

        string left = s.substr(0, pos);
        string mid = s.substr(pos + 1, end - pos - 1);
        string right = s.substr(end + 1);

        set<string> L = solve(left);
        set<string> M = solve(mid);
        set<string> R = solve(right);

        for (string a : L)
            for (string b : M)
                for (string c : R)
                    res.insert(a + b + c);

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        set<string> ans = solve(expression);
        return vector<string>(ans.begin(), ans.end());
    }
};