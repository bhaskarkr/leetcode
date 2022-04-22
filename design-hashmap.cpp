class MyHashMap {
public:
    vector<list<pair<int, int>>> cMap;
    int prime;
    MyHashMap() {
        prime = 10007;
        cMap = vector<list<pair<int, int>>>(prime);
    }
    
    list<pair<int, int>>:: iterator search(int key) {
        int hashKey = key%prime;
        for(auto start = cMap[hashKey].begin(); start != cMap[hashKey].end(); start++) {
            if(start->first == key)
                return start;
        }
        return cMap[hashKey].end();
    }
    
    void put(int key, int value) {
        int hashKey = key%prime;
        auto it = search(key);
        if( it == cMap[hashKey].end()) {
            cMap[hashKey].push_back({key, value});
        } else {
            if(it->second != value) {
                cMap[hashKey].erase(it);
                cMap[hashKey].push_back({key, value});
            }
        }
    }
    
    int get(int key) {
        int hashKey = key%prime;
        auto it = search(key);
        if( it == cMap[hashKey].end())
            return -1;
        return it->second;
    }
    
    void remove(int key) {
         int hashKey = key%prime;
        auto it = search(key);
        if( it != cMap[hashKey].end()) {
            cMap[hashKey].erase(it);
        }
    }
};
