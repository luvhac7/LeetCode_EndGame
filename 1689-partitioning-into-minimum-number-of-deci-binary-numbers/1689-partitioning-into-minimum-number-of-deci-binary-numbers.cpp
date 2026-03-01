class Solution {
public:
    int minPartitions(string n) {
       sort(n.begin(),n.end());
       int x=n.size();
       cout<<n<<" ";
       return n[x-1]-'0';
    }
};