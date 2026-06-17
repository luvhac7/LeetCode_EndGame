class Solution {
public:
    int singleNumber(vector<int>& a) {
        //1
        // map<int,int>f;for(int i:a) f[i]++;
        // for(auto &i:f){
        //     if(i.second==1) return i.first;
        // }
        // return -1;
        //2
        // int x=0;
        // for(int i:a)
        //     x^=i;
        // return x;
        //3
        set<int>st;
        for(int i:a)
        {
            if(st.find(i)!=st.end())
            {
                st.erase(i);
            }
            else {
                st.insert(i);
            }
        }
        return *st.begin();
    }
};