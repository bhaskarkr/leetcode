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
