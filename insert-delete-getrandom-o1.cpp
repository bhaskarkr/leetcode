class RandomizedSet {
public:
    vector<int> data;
    unordered_map<int, int> valToIndex;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(valToIndex.find(val) != valToIndex.end())
            return false;
        valToIndex[val] = data.size();
        data.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(valToIndex.find(val) == valToIndex.end())
            return false;
        swap(data[valToIndex[val]], data.back());
        valToIndex[data[valToIndex[val]]] = valToIndex[val];
        valToIndex.erase(val);
        data.pop_back();
        return true;
    }
    
    int getRandom() {
        return data[rand() % data.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
