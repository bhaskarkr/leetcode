class LFUCache {
public:
    int cap;
    int minFreq;
    int totalKey;
    unordered_map<int, pair<int, int>> keyToValAndFreq;
    unordered_map<int, list<int>::iterator> keyToListIter;
    unordered_map<int, list<int>> freqToList;
    LFUCache(int capacity) {
        cap = capacity;
        totalKey = 0;
    }
    
    int get(int key) {
        if(keyToValAndFreq.find(key) == keyToValAndFreq.end())
            return -1;
        freqToList[keyToValAndFreq[key].second].erase(keyToListIter[key]);
        keyToValAndFreq[key].second++;
        freqToList[keyToValAndFreq[key].second].push_back(key);
        keyToListIter[key] = prev(freqToList[keyToValAndFreq[key].second].end());
        while(freqToList[minFreq].size() == 0)
            minFreq++;
        return keyToValAndFreq[key].first;
    }
    
    void put(int key, int value) {
        if(cap < 1)
            return;
        int existingVal = get(key);
        if(existingVal != -1) {
            // get function already updated the freq and iterator
            keyToValAndFreq[key].first = value;
            return;
        }
        if(totalKey >= cap) {
            keyToValAndFreq.erase(freqToList[minFreq].front());
            keyToListIter.erase(freqToList[minFreq].front());
            freqToList[minFreq].pop_front();
            totalKey--;
        }
        keyToValAndFreq[key] = {value, 1};
        freqToList[1].push_back(key);
        keyToListIter[key] = prev(freqToList[1].end());
        minFreq = 1;
        totalKey++;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
