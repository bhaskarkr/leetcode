class Leaderboard {
public:
    set<pair<int, int>> s;
    map<int, int> m;
    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
        if(m.find(playerId) != m.end()) {
            s.erase({m[playerId], playerId});
        }
        m[playerId] += score;
        s.insert({m[playerId], playerId});
    }
    
    int top(int K) {
        int ans = 0;
        int i = 0;
        for(auto itr = s.rbegin(); itr != s.rend() && i < K; itr++, i++) {
            ans += itr->first;
        }
        return ans;
    }
    
    void reset(int playerId) {
        if(m.find(playerId) != m.end()) {
            s.erase({m[playerId], playerId});
            m.erase(playerId);
        }
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
