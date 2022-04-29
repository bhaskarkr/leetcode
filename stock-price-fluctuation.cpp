class StockPrice {
public:
    multiset<int> mSet;
    unordered_map<int, int> umap;
    int maxTimestamp;
    StockPrice() {
    }
    
    void update(int timestamp, int price) {
        maxTimestamp  = max(maxTimestamp, timestamp);
        if(umap[timestamp] != 0) {
            mSet.erase(mSet.find(umap[timestamp]));
        }    
        mSet.insert(price);
        umap[timestamp] = price;
    }
    
    int current() {
       return umap[maxTimestamp];
    }
    
    int maximum() {
        return *mSet.rbegin();
    }
    
    int minimum() {
        return *mSet.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
