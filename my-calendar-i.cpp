class MyCalendar {
public:
    map<int, int> m;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        // both upper and lower works
        auto it = m.lower_bound(start);
        if(it != m.end() && it->first < end)
            return false;
        if(it != m.begin() && (--it)->second > start)
            return false;
        m[start] = end;
        return true;
    }
};


class MyCalendar {
public:
    map<int, int> umap;
    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto itr = umap.lower_bound(endTime);
        if(itr != umap.begin() && prev(itr)->second > startTime) {
            return false;
        }
        umap[startTime] = endTime;
        return true;
            
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
