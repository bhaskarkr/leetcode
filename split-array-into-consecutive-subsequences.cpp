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
