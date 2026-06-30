class Solution {
public:
typedef vector<int> vi;
vi digit(int n)
{
    vi d;
    while(n>0)
    {
        d.push_back(n%10);n/=10;
    }
    return d;
}
    int countDigitOccurrences(vector<int>& a, int t) {
        int cnt=0;
        for(int i:a)
        {
            vi d=digit(i);
            for(int j=0;j<d.size();j++)
            {
                if(d[j]==t) cnt++;
            }
        }
        return cnt;
    }
};