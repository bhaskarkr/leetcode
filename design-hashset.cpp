class MyHashSet {
public:
    int mod = 10007;
    vector<list<int>> cMap;
    MyHashSet() {
        cMap = vector<list<int>>(mod);
    }
    
    void add(int key) {
        int hashKey = key%mod;
        if(search(key) == cMap[hashKey].end())
            cMap[hashKey].push_back(key);
    }
    
    void remove(int key) {
        int hashKey = key%mod;
        auto it = search(key);
        if(it != cMap[hashKey].end())
            cMap[hashKey].erase(it);
    }
    
    list<int>::iterator search(int key) {
        int hashKey = key%mod;
        return find(cMap[hashKey].begin(), cMap[hashKey].end(), key);
    }
    
    bool contains(int key) {
        int hashKey = key%mod;
        return search(key) != cMap[hashKey].end();
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
