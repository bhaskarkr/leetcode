class CountIntervals {
public:
    map<int, int> mp;
    int counts = 0;
    CountIntervals() {
        mp[0] = 0;
    }
    
    void add(int left, int right) {
        auto itr = mp.upper_bound(left);
        if(prev(itr)->second >= left)
            itr = prev(itr);
        for(;itr != mp.end() && itr->first <= right; mp.erase(itr++)) {
            left = min(left, itr->first);
            right = max(right, itr->second);
            counts -= itr->second - itr->first + 1;
        }
        counts += right - left + 1;
        mp[left] = right;
    }
    
    int count() {
        return counts;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */
