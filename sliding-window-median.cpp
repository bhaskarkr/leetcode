/**
*   mid is pointing to the right one, so if there is any change in the left
    then we need to update the mid otherwise we can leave mid as it is
    next (of end) return 0 when * is used
    prev(of begin) return error if its before begin
    so its safe to use prev() and next for begin and end
    Another point, next(x, 0) still points to the next element. 
*/

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> ms(nums.begin(), nums.begin() + k);
        auto mid = next(ms.begin(), k/2);
        cout<<*(prev(nums.begin(), 0))<<endl;
        vector<double> ans;
        for(int i = k; i < nums.size(); i++) {
            ans.push_back((double(*mid) + *prev(mid, 1 - k % 2)) / 2);
            ms.insert(nums[i]);
            if(nums[i] < *mid)
                --mid;
            if(nums[i-k] <= *mid)
                ++mid;
            ms.erase(ms.lower_bound(nums[i-k]));
        }
        ans.push_back((double(*mid) + *prev(mid, 1 - k%2)) / 2);
        return ans;
    }
};
