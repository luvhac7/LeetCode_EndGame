class Solution {
public:



    int lengthOfLongestSubstring(string s) {
    set<char>st;
    int maxlen=0;
    int left=0;

    for(int right=0;right<s.size();right++)
    {
        while(st.count(s[right]))
        {
            st.erase(s[left]);left++;
        }
        st.insert(s[right]);
        maxlen=max(maxlen,(int)st.size());
    }
    return maxlen;
    }
};