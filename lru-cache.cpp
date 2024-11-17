class LRUCache {
public:
    int limit = 0;
    list<pair<int, int>> kv;
    unordered_map<int, list<pair<int, int>>::iterator> umap;
    LRUCache(int capacity) {
        limit = capacity;
    }   
    
    int get(int key) {
        if(umap.find(key) == umap.end())
            return -1;
        auto temp = *(umap[key]);
        kv.erase(umap[key]);
        umap.erase(key);
        kv.push_front(temp);
        umap[key] = kv.begin();
        return temp.second;
    }
    
    void put(int key, int value) {
        if(umap.find(key) != umap.end()) {
            kv.erase(umap[key]);
            umap.erase(key);
        }
        if(umap.size() == limit) {
            umap.erase(kv.back().first);
            kv.pop_back();
        }
        kv.push_front({key, value});
        umap[key] = kv.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
