class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int, int>> temp;
        for(int i = 0; i < nums.size(); i++) {
            temp.push_back({nums[i], i});
        }
        sort(temp.begin(), temp.end());
        for(int i = 0; i < nums.size(); i++) {
            if(i > 0 && temp[i].first == temp[i-1].first)
                nums[temp[i].second] = nums[temp[i-1].second];
            else
                nums[temp[i].second] = i;
        }
        return nums;
    }
};
