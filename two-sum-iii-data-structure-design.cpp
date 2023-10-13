class TwoSum {
public:
    multiset<int> um;
    TwoSum() {
        
    }
    void add(int number) {
        um.insert(number);
    }
    bool find(int value) {
        if(!um.empty()) {
            auto s = um.begin(), e = prev(um.end());
            while(s != e) {
                int t = *s + *e;
                if(t == value)
                    return true;
                else if(t < value)
                    s++;
                else
                    e--;
            } 
        }
        return false;
    }
};
