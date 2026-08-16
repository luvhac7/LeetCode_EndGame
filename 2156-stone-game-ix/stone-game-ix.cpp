class Solution {
public:
bool f(vector<int>&a)
{
    vector<int>cnt(3,0);
    for(int i:a) cnt[i%3]++;
    if(cnt[0]%2==0) return cnt[1]>0 && cnt[2]>0;
    else return abs(cnt[1]-cnt[2])>2;
}
    
    bool stoneGameIX(vector<int>& a) {
      return f(a);
    }
};