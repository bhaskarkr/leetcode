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


class LRUCache {
public:
    list<pair<int, int>> list_pair;
    unordered_map<int, list<pair<int, int>> :: iterator> umap;
    int max_capacity = 0;
    LRUCache(int capacity) {
        max_capacity = capacity;
    }
    
    int get(int key) {
        if(umap.find(key) == umap.end()) {
            return -1;
        }
        auto val = *umap[key];
        list_pair.erase(umap[key]);
        list_pair.push_front({key, val.second});
        umap[key] = list_pair.begin();
        return val.second;
    }
    
    void put(int key, int value) {
        if(umap.find(key) != umap.end()) {
            list_pair.erase(umap[key]);
        } 
        else if(umap.size() >= max_capacity) {
            auto temp = list_pair.back().first;
            list_pair.pop_back();
            umap.erase(temp);
        }
        list_pair.push_front({key, value});
        umap[key] = list_pair.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
