class Solution {
public:
    int maxIceCream(vector<int>& a, int t) {
        int s=0;sort(a.begin(),a.end());
        for(int i:a)
        {
            if(t>=i)
            { s++;
                t-=i;
            }
            else break;
        }
        return s;
    }
};