class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<int> s;
        int n = nums.size();
        for(int i = 0, j = 0; i < n; i++) {
            if(s.size() > indexDiff)
                s.erase(s.find(nums[j++]));
            auto itr = s.upper_bound(nums[i] + valueDiff);
            if(itr != s.begin() && abs(*prev((itr)) - nums[i]) <= valueDiff)
                return true;
            s.insert(nums[i]);
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        multiset<int> s;
        int n = nums.size();
        for(int i = 0, j = 0; i < n; i++) {
            if(s.size() > indexDiff) {
                s.erase(s.find(nums[j++]));
            }
            auto itr = s.lower_bound(nums[i] - valueDiff);
            if(itr != s.end() && *(itr) - nums[i] <= valueDiff) {
                return true;
            }
            s.insert(nums[i]);
        }
        return false;
    }
};
