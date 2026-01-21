class Trie{
    struct Node{
        Node* ch[2]={nullptr,nullptr};//child node
    };
    Node* root;
    public:
    Trie(){
        root=new Node();

    }
    void insert(int n)
    {
        Node* cur=root;
        for(int i=31;i>=0;i--)
        {
            int b=(n>>i)&1;
            if(!cur->ch[b])
                cur->ch[b]=new Node();
            cur=cur->ch[b];
        }
    }
    int maxi(int x)
    {
        Node* cur=root;
        int ans=0;
        for(int i=31;i>=0;i--)
        {
            int b=(x>>i)&1;
            if(cur->ch[1-b]){
                ans|=(1<<i);
                cur=cur->ch[1-b];
            }
            else{
                cur=cur->ch[b];
            }
        }
        return ans;
    }
    bool isem(){
        return !root->ch[0] && !root->ch[1];
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& a, vector<vector<int>>& qu) {
        sort(a.begin(),a.end());
        vector<array<int,3>>q;
        for(int i=0;i<qu.size();i++)
        {
            q.push_back({qu[i][1],qu[i][0],i});
        }
        sort(q.begin(),q.end());
        Trie tr;
        vector<int>ans(qu.size());
        int idx=0;
        for(auto &[mi,xi,qi]:q){
            while(idx<a.size() && a[idx]<=mi){
                tr.insert(a[idx]);idx++;
            }
            if(tr.isem()){
                ans[qi]=-1;
            }
            else{
                ans[qi]=tr.maxi(xi);
            }
        }
        return ans;

    }
};