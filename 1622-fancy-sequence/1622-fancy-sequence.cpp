class Fancy {
public:
    vector<long long> sequence;

    Fancy() {
        sequence.clear();
    }
    
    void append(int val) {
        sequence.push_back(val);
    }
    
    void addAll(int inc) {
        for(auto& val : sequence) {
            val += inc;
        }
    }
    
    void multAll(int m) {
        for(auto& val : sequence) {
            val *= m;
            val %= (int)(1e9 + 7);
        }
    }
    
    int getIndex(int idx) {
        if(sequence.size() > idx) {
            return (sequence[idx] % (int)(1e9 + 7));
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