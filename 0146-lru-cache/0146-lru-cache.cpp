class Node{
    public:
    int key,value;
    Node* prev;
    Node* next;
    Node(int key,int value):key(key),value(value),prev(nullptr),next(nullptr){}
};
class LRUCache {
private:
    int cap;
    unordered_map<int,Node*>mp;
    Node* head;
    Node* tail;
    void rem(Node* node)
    {
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }
    void insert(Node* node)
    {
        node->next=head->next;
        node->prev=head;
        head->next->prev=node;
        head->next=node;
    }
public:
    LRUCache(int cap) {
    this->cap=cap;
    head=new Node(0,0);
    tail=new Node(0,0);
    head->next=tail;
    tail->prev=head;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end())
        {
            Node* node=mp[key];
            rem(node);
            insert(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int val) {
        if(mp.find(key)!=mp.end())
        {
Node* node=mp[key];
rem(node);
mp.erase(key);
delete node;        }
        if(mp.size()==cap)
        {
            Node* lru=tail->prev;
            mp.erase(lru->key);
            rem(lru);
            delete lru;
        }
        Node* node=new Node(key,val);
        insert(node);
        mp[key]=node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */