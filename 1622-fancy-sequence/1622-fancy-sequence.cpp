class Fancy {
typedef long long ll;
public:
    vector<ll>s;

    Fancy() {
        s.clear();
    }
    
    void append(int val) {
        s.push_back(val);
    }
    
    void addAll(int inc) {
        for(auto& val : s) {
            val += inc;
        }
    }
    
    void multAll(int m) {
        for(auto& val : s) {
            val *= m;
            val %= (int)(1e9 + 7);
        }
    }
    
    int getIndex(int idx) {
        if(s.size() > idx) {
            return (s[idx] % (int)(1e9 + 7));
        } else {
            return -1;
        }
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */