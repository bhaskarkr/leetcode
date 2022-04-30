class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        int n =  asteroids.size();
        for(int i = 0; i < n; i++) {
            while(!stk.empty()  && stk.back() > 0 && stk.back() < -asteroids[i])
                stk.pop_back();
            if(stk.empty() || asteroids[i] > 0 || stk.back() < 0)
                stk.push_back(asteroids[i]);
            else if(!stk.empty() && -asteroids[i] == stk.back())
                stk.pop_back();
        }
        return stk;
    }
};
