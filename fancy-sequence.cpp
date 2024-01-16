class Fancy {
public:
    int mod = 1e9 + 7;
    unsigned long sum = 0, prod = 1;
    vector<unsigned long> vals; 
    unsigned long modPow(unsigned long x, int y) {
        unsigned long total = 1, p = x;
        for(;y; y >>= 1) {
            if(y & 1)
                total = (total * p) % mod;
            p = (p * p) % mod;
        }
        return total;
    }
    Fancy() {
        
    }
    
    void append(int val) {
        vals.push_back((((mod + val - sum) % mod)*modPow(prod, mod - 2))%mod);
    }
    
    void addAll(int inc) {
        sum = (sum + inc) % mod;
    }
    
    void multAll(int m) {
        sum = (sum * m) % mod;
        prod = (prod * m) % mod;
    }
    
    int getIndex(int idx) {
        if(idx >= vals.size())
            return -1;
        return (((vals[idx] * prod) % mod) + sum) % mod;
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
