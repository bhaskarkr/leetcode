class RLEIterator {
public:
    int ind;
    vector<int> encod;
    RLEIterator(vector<int>& encoding) {
        encod = encoding;
        ind = 0;
    }
    int next(int n) {
        while(ind < encod.size() && encod[ind] < n) {
            n-=encod[ind];
            ind += 2;
        }
        if(ind >= encod.size())
            return -1;
        encod[ind] -= n;
        return encod[ind+1];
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */
