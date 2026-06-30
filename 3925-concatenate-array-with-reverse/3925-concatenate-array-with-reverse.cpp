class Solution {
public:
typedef vector<int> vi;
    vector<int> concatWithReverse(vector<int>& a) {
        vi ans=a;reverse(a.begin(),a.end());for(int i:a) ans.push_back(i);
        return ans;
    }
};