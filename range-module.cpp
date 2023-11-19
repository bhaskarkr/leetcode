class RangeModule {
public:
    map<int, int> intervals;
    RangeModule() {
    }
    
    void addRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        while(it != intervals.end() && it->first <= right) {
            right = max(right, it->second);
            it++;
            intervals.erase(prev(it));
        }
        if(it != intervals.begin() && (--it)->second >= left) {
            it->second = max(it->second, right);
        } else {
            intervals[left] = right;
        }
    }
    
    bool queryRange(int left, int right) {
        auto l = intervals.upper_bound(left);
        if(l == intervals.begin()) 
            return false;
        return right <= prev(l)->second;
    }
    
    void removeRange(int left, int right) {
        auto it = intervals.upper_bound(left);
        int finalEnd = -1;
        while(it != intervals.end() && it->first <= right) {
            finalEnd = max(finalEnd, it->second);
            it++;
            intervals.erase(prev(it));
        }
        if(it != intervals.begin() && (--it)->second >= left) {
            finalEnd = max(it->second, finalEnd);
            it->second = left;
        }
        if(right < finalEnd)
            intervals[right] = finalEnd;
        
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */
