class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int dominant = nums[0], c = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == dominant)
                c++;
            else
                c--;
            if(c == 0) {
                dominant = nums[i];
                c = 1;
            }
        }
        int total = 0;
        for(auto &num : nums)
            if(dominant == num)
                total++;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            count += nums[i] == dominant;
            if(count * 2 > (i + 1) && (total - count) * 2 > (nums.size() - i - 1))
                return i;
        }
        return -1;
    }
};



class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        priority_queue<pair<int, int>> left, right;
        unordered_map<int , int> umap, leftCount;
        for(int i = 0; i < nums.size(); i++)
            umap[nums[i]]++;
        for(auto &[k,v] : umap)
            right.push({v, k});
        for(int i = 0; i < nums.size() - 1; i++) {
            umap[nums[i]]--;
            while(!right.empty() && umap[right.top().second] < right.top().first) {
                int ele = right.top().second;
                right.pop();
                if(umap[ele] > 0)
                    right.push({umap[ele], ele});
            }
            leftCount[nums[i]]++;
            while(!left.empty() && left.top().first < leftCount[nums[i]])
                left.pop();
            left.push({leftCount[nums[i]], nums[i]});
            if(left.top().second == right.top().second && left.top().first * 2 > (i+1) && right.top().first * 2 > (nums.size() - i - 1))
                return i;
        }       
        return -1;
    }
};
