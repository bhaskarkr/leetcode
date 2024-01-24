class Solution {
public:
    bool isPossible(vector<int>& nums) {
        /**
             1, 2, 3, 4, 5, 5, 6, 7
             cnt  = [ 1 - 1 , 2 - 1 , 3 - 1 , 4 - 1 , 5 - 2 ,  6 - 1 , 7 - 1 ]
             tail = [ 1 - 0 , 2 - 0 , 3 - 0 , 4 - 0 , 5 - 0 ,  6 - 0 , 7 - 0 ]
             
             cnt  = [ 1 - 0 , 2 - 0 , 3 - 0 , 4 - 1 , 5 - 1 ,  6 - 1 , 7 - 1 ]
             tail = [ 1 - 0 , 2 - 0 , 3 - 0 , 4 - 1 , 5 - 0 ,  6 - 0 , 7 - 0 ]
             
             cnt  = [ 1 - 0 , 2 - 0 , 3 - 0 , 4 - 0 , 5 - 0 ,  6 - 0 , 7 - 1 ]
             tail = [ 1 - 0 , 2 - 0 , 3 - 0 , 4 - 1 , 5 - 0 ,  6 - 1 , 7 - 0 ]
              
             cnt  = [ 1 - 0 , 2 - 0 , 3 - 0 , 4 - 0 , 5 - 0 ,  6 - 0 , 7 - 0 ]
             tail = [ 1 - 0 , 2 - 0 , 3 - 0 , 4 - 1 , 5 - 0 ,  6 - 0 , 7 - 1 ]
        */
        unordered_map<int, int> cnt, tail;
        for(auto num : nums)
            cnt[num]++;
        for(int num : nums) {
            if(cnt[num]) {
                cnt[num]--;
                if(tail[num-1]) {
                    tail[num-1]--;
                    tail[num]++;
                } else if(cnt[num+1]&&cnt[num+2]) {
                    cnt[num+1]--;
                    cnt[num+2]--;
                    tail[num+2]++;
                } else
                    return false;
            }
        }
        return true;
    }
};


class Solution {
public:
    bool isPossible(vector<int>& nums) {
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
            if(a.first == b.first)
                return a.second > b.second; 
            return a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for(int num : nums) {
            while(!pq.empty() && pq.top().first + 1 < num) {
                if(pq.top().second < 3)
                    return false;
                pq.pop();
            }
            if(pq.empty() || pq.top().first == num) {
                pq.push({num, 1});
            } else {
                auto tp = pq.top();
                pq.pop();
                pq.push({num, tp.second + 1});
            }
        }
        while(!pq.empty()) {
            auto tp = pq.top();
            pq.pop();
            if(tp.second < 3)
                return false;
        }
        return true;
    }
};
