class Solution {
public:
    int closestTarget(vector<string>& w, string t, int si) {
        int n=w.size();
        int left=si,right=si;
        int step=0;
        while(true)
        {
            if(w[left]==t || w[right]==t)
            {
                return step;
            }
            left=(left-1+n)%n;
            right=(right+1)%n;
            step++;
            if(left==right)
            {
                if(w[left]==t) return step;
                break;
            }
        }
        return -1;
    }
};