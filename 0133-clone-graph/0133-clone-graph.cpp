/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
typedef Node N;
unordered_map<N*,N*>mp;
N* dfs(N* cur)
{
if(!cur) return nullptr;
if(mp.count(cur))
{
    return mp[cur];
}
N* copy=new N(cur->val);
mp[cur]=copy;
for(auto i:cur->neighbors)
{
    copy->neighbors.push_back(dfs(i));
}
return copy;
}
    Node* cloneGraph(Node* cur) {
        if(!cur) return nullptr;
        return dfs(cur);
    }
};