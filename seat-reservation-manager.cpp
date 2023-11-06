class SeatManager {
public:
    int k;
    set<int> r, u;
    SeatManager(int n) {
        k = 1;
    }
    
    int reserve() {
        if(u.empty()) {
            r.insert(k++);
            return k - 1;
        } 
        int m = *(u.begin());
        r.insert(*(u.begin()));
        u.erase(u.begin());
        return m;

    }
    
    void unreserve(int seatNumber) {
        u.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
