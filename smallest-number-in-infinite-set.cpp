class SmallestInfiniteSet {
public:
    set<int> PQ;
    SmallestInfiniteSet() {
        PQ.insert(1);
    }
    
    int popSmallest() {
        int x = *(PQ.begin());
        PQ.erase(PQ.begin());
        if(PQ.empty())
            PQ.insert(x+1);
        return x;
    }
    
    void addBack(int num) {
        if(num < *(PQ.rbegin()))
            PQ.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
